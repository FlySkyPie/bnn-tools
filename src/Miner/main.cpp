#include <cstdlib>
#include <iostream>
#include <boost/program_options.hpp>
#include <algorithm> //max
#include <sstream>  //stringstream

using namespace std;
namespace po = boost::program_options;

typedef unsigned char uchar;

uchar* createMask(int geneAddressing) {
    uint* mask = new uint[4];
    int32_t shift[] = {
        min(max(8 - geneAddressing,0), 8),
        min(max(16 - geneAddressing,0), 8),
        min(max(24 - geneAddressing,0), 8),
        min(max(32 - geneAddressing,0), 8),
    };
    mask[0] = (0xff >> shift[0]); //LSB in 0b00000001
    mask[1] = (0xff >> shift[1]);
    mask[2] = (0xff >> shift[2]);
    mask[3] = (0xff >> shift[3]); //MSB in 0b10000000

    uchar* charMask = new uchar[4];
    charMask[0] = mask[0];
    charMask[1] = mask[1];
    charMask[2] = mask[2];
    charMask[3] = mask[3];/**/

    return charMask;
}

uchar* maskCharArray(uchar* array, uchar* mask) {
    uchar* result = new uchar[4];
    result[0] = 0xff & array[0] & mask[0]; //LSB in 0b00000001
    result[1] = 0xff & array[1] & mask[1];
    result[2] = 0xff & array[2] & mask[2];
    result[3] = 0xff & array[3] & mask[3]; //MSB in 0b10000000

    return result;
}

uint32_t parseLink(uchar* array) {
    uint32_t value = 0x0000 +
        (uint32_t)array[0] * 0x1 +
        (uint32_t)array[1] * 0x100 +
        (uint32_t)array[2] * 0x10000 +
        (uint32_t)array[3] * 0x1000000;

    return value;
}

string createGeneJsonl(uchar* rand1, uchar* rand2, uchar* randWeight, uint32_t geneScale) {
    uchar* mask = createMask(geneScale);
    uchar* link1 = maskCharArray(rand1, mask);
    uchar* link2 = maskCharArray(rand2, mask);
    bool weight = randWeight[0] & 0x01;
    string gene;
    stringstream ss;
    ss << "{\"type\":\"link\""
        << ",\"from\":" << parseLink(link1)
        << ",\"to\":" << parseLink(link2)
        << ",\"weight\":" << (weight ? "1" : "0") << "}\n";
    return ss.str();
}

string createHeader(uint32_t geneScale) {
    stringstream ss;
    ss << "{\"type\":\"head\""
        << ",\"scale\":" << geneScale << "}\n";
    return ss.str();
}

/**
 * To randomly generate chromosome as original species.
 */
int main(int argc, char** argv) {
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("scale", po::value<uint32_t>(), "length of addressing space")
        ("size", po::value<uint32_t>(), "how many genes will generated");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        cerr << desc << "\n";
        return 1;
    }
    if (!vm.count("scale")) {
        cerr << "Length of address was not set.\n";
        return 1;
    }

    if (!vm.count("size")) {
        cerr << "Amount of genes was not set.\n";
        return 1;
    }

    uchar str[9];
    uint32_t geneScale = vm["scale"].as<uint32_t>();
    uint32_t chromosomeSize = vm["size"].as<uint32_t>();
    uint32_t count = 0;

    std::cout << createHeader(geneScale);
    while (1) {
        for (int i = 0;i < 9;i++) {
            str[i] = static_cast<uchar>(std::cin.get());
        }

        uchar link1[] = {
            str[0],str[1],str[2],str[3]
        };
        uchar link2[] = {
            str[4],str[5],str[6],str[7]
        };
        uchar weight[]{
            str[8]
        };

        std::cout << createGeneJsonl(&link1[0], &link2[0], &weight[0], geneScale);
        count += 1;

        if (count == chromosomeSize) {
            break;
        }
    }

    return 0;
}