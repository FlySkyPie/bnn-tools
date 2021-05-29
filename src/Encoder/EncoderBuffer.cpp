#include <stdexcept>
#include <algorithm>

#include "EncoderBuffer.h"

typedef unsigned char uchar;

EncoderBuffer::EncoderBuffer(uint32_t scale) {
    this->scale = scale;
    this->counter = 0;
    this->size = (scale / 8) + ((scale % 8) ? 1 : 0);
}

EncoderBuffer::~EncoderBuffer() {
}

bool EncoderBuffer::addLink(LinkDescriptor link) {
    if (this->counter == 8) {
        throw std::runtime_error("The buffer already full, pleace dump first.");
        return true;
    }

    this->weightBuffer = (this->weightBuffer << 1) | (0x01 & link.weight);
    this->stringBuffer +=
        this->coverInt2String(link.from, this->size) + this->coverInt2String(link.to, this->size);
    this->counter += 1;
    return (this->counter == 8);
}

std::string EncoderBuffer::dump() {
    if (this->counter != 8) {
        this->weightBuffer = this->weightBuffer << (8 - this->counter);
    }

    std::string result;
    result = (char)this->weightBuffer + this->stringBuffer;
    this->weightBuffer = 0x00;
    this->stringBuffer.clear();
    this->counter = 0;
    return result;
}

bool EncoderBuffer::isEmpty() {
    return this->counter == 0;
}

std::string EncoderBuffer::coverInt2String(uint32_t value, uint32_t size) {
    char* array = new char[size];
    for (int i = 0;i < size;i++) {
        array[i] = (value >> (8 * i)) & 0xff;
    }
    std::string string(array, size);
    std::reverse(string.begin(), string.end());
    return string;
}