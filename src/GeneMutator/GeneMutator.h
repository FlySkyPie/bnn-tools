#pragma once
#include <string>
#include <cstdint>
#include <random>

typedef unsigned char uchar;
typedef struct LinkDescriptorType LinkDescriptor;
struct LinkDescriptorType
{
    uint32_t from;
    uint32_t to;
    bool weight;
};

class GeneMutator {
public:
    GeneMutator(uint32_t scale, float probability);
    virtual ~GeneMutator();

    std::string mutateGeneJsonl(std::string line);

private:
    uint32_t scale;
    uint32_t size;
    uchar* mask;

    std::random_device randDevice;
    std::mt19937* randNumber;
    std::bernoulli_distribution* bernoulli;

    uchar* createRandMask();
    uint32_t mutateValue(uint32_t value);
    bool rand();
};
