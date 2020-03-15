#pragma once
#include <cstring>
#include <cstdint>

#include "Chromosome.h"

class Decoder {
public:
    Decoder();
    virtual ~Decoder();
    std::string convertToJson(Chromosome* chromosome);
    
private:
    uint8_t addressLength;
    uint8_t readAddressLength(Chromosome* chromosome);
    bool readGeneSegment(
            Chromosome* chromosome,
            uint32_t &nodeAddress1,
            uint32_t &nodeAddress2,
            bool &gene);

    bool readAddress(Chromosome* chromosome, uint32_t &nodeAddress);
};
