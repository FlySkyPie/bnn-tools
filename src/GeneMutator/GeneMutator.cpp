#include <sstream>  //stringstream
#include <rapidjson/document.h>
#include <algorithm>    //reverse

#include "GeneMutator.h"

using namespace rapidjson;
using namespace std;


LinkDescriptor parseLinkJsonl(string line) {
    Document document;
    document.Parse(line.c_str());

    LinkDescriptor link = {
       static_cast<uint32_t>(document["from"].GetInt()),
       static_cast<uint32_t>(document["to"].GetInt()),
       document["weight"].GetInt() != 0,
    };
    return link;
}

uchar* covertInt2CharArray(uint32_t value, uint32_t size) {
    uchar* array = new uchar[size];
    for (int i = 0;i < size;i++) {
        array[size - 1 - i] = (value >> (8 * i)) & 0xff;
    }

    return array;
}

uint32_t parseValue(uchar* array, uint32_t size) {
    uint32_t value = 0x0000;
    for (int i = 0;i < size;i++) {
        value += ((uint32_t)array[i]) << (8 * i);
    }
    return value;
}

GeneMutator::GeneMutator(uint32_t scale, float probability) {
    this->randNumber = new std::mt19937(this->randDevice());
    this->bernoulli = new std::bernoulli_distribution(probability);

    this->scale = scale;
    this->size = (scale / 8) + ((scale % 8) ? 1 : 0);

    //create mask
    uint32_t mod = scale % 8;
    uint32_t size = (scale / 8) + ((mod) ? 1 : 0);
    uchar* mask = new uchar[size];
    for (int i = 0;i < size;i++) {
        if (mod && i == size - 1) {
            mask[i] = 0xff >> (8 - (mod));
            continue;
        }
        mask[i] = 0xff;
    }
    this->mask = mask;
}

GeneMutator::~GeneMutator() {
    delete[] this->mask;
    delete this->randNumber;
    delete this->bernoulli;
}

string GeneMutator::mutateGeneJsonl(string line) {
    LinkDescriptor descriptor = parseLinkJsonl(line);

    uint32_t from = this->mutateValue(descriptor.from);
    uint32_t to = this->mutateValue(descriptor.from);
    bool weight = descriptor.weight ^ this->rand();

    stringstream ss;
    ss << "{\"type\":\"link\""
        << ",\"from\":" << from
        << ",\"to\":" << to
        << ",\"weight\":" << (weight ? "1" : "0") << "}\n";
    return ss.str();
}

uchar* GeneMutator::createRandMask() {
    uchar* mask = new uchar[size];
    for (int i = 0;i < size;i++) {
        mask[i] =
            (0x01 & this->rand()) |
            (0x02 & this->rand()) |
            (0x04 & this->rand()) |
            (0x08 & this->rand()) |
            (0x10 & this->rand()) |
            (0x20 & this->rand()) |
            (0x40 & this->rand()) |
            (0x80 & this->rand());
    }
    return mask;
}

uint32_t GeneMutator::mutateValue(uint32_t value) {
    uchar* charValue = covertInt2CharArray(value, this->size);
    uchar* randMask = this->createRandMask();
    for (int i = 0;i < this->size;i++) {
        charValue[i] = (charValue[i] ^ randMask[i]) & this->mask[i];
    }
    uint32_t newValue = parseValue(charValue, this->size);
    delete[] charValue;
    delete[] randMask;
    return newValue;
}

bool GeneMutator::rand() {
    return this->bernoulli->operator()(*this->randNumber);
}