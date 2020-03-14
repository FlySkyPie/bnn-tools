#pragma once

#include <cstdint>
#include "Chromosome.h"
#include "BernoulliJudge.h"

class Generator {
public:
    Generator(uint8_t addressLength, uint32_t genesAmount);
    virtual ~Generator();
    Chromosome* getChromosome();
private:
    uint8_t addressLength;
    uint32_t genesAmount;
    BernoulliJudge* bernoulliJudge;
    Chromosome* getRadomGeneSegment();
};
