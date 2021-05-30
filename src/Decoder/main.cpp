#include <cstdlib>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <boost/program_options.hpp>

using namespace std;
namespace po = boost::program_options;
typedef unsigned char uchar;

string createHeader(uint32_t geneScale) {
    stringstream ss;
    ss << "{\"type\":\"head\""
        << ",\"scale\":" << geneScale << "}\n";
    return ss.str();
}

uint32_t parseLink(uchar* array, uint32_t size) {
    uint32_t value = 0x0000;
    for (int i = 0;i < size;i++) {
        value += ((uint32_t)array[i]) << (8 * i);
    }
    return value;
}

string createGeneJsonl(uchar* node1, uchar* node2, bool weight, uint32_t size) {
    string gene;
    stringstream ss;
    ss << "{\"type\":\"link\""
        << ",\"from\":" << parseLink(node1, size)
        << ",\"to\":" << parseLink(node2, size)
        << ",\"weight\":" << (weight ? "1" : "0") << "}\n";
    return ss.str();
}

/**
 * Decode binary chromosome to jsonl
 */
int main(int argc, char** argv)
{
    uint32_t scale = static_cast<uchar>(cin.get());
    cout << createHeader(scale);

    uint32_t size = (scale / 8) + ((scale % 8) ? 1 : 0);

    while (1) {
        uchar weightBuffer = static_cast<uchar>(cin.get());
        for (int i = 0;i < 8;i++) {
            bool weight = (weightBuffer >> (7 - i)) & 0x01;

            uchar* node1 = new uchar[size];
            for (int j = 0;j < size;j++) {
                node1[size - 1 - j] = static_cast<uchar>(cin.get());
            }
            uchar* node2 = new uchar[size];
            for (int j = 0;j < size;j++) {
                node2[size - 1 - j] = static_cast<uchar>(cin.get());
            }

            if (cin.eof()) {
                break;
            }
            cout << createGeneJsonl(node1, node2, weight, size);
            delete[] node1;
            delete[] node2;
        }
        if (cin.eof()) {
            break;
        }
    }

    return 0;
}
