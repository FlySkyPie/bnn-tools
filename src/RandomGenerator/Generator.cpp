#include <cstdint>

#include "Generator.h"
#include "BernoulliJudge.h"


Generator::Generator(uint8_t addressLength, uint32_t genesAmount) {
    if (addressLength == 0) {
        this->addressLength = 1;
    } else if (addressLength > 32) {
        this->addressLength = 32;
    } else {
        this->addressLength = addressLength;
    }
    this->genesAmount = genesAmount;
    this->bernoulliJudge = new BernoulliJudge(0.5);
}

Generator::~Generator() {
    delete this->bernoulliJudge;
}

Chromosome* Generator::getChromosome() {
    Chromosome *chromosome = new Chromosome();
    chromosome->addGenes(this->addressLength);
    for (uint32_t i = 0; i < this->genesAmount; i++) {
        Chromosome *geneSegment = this->getRadomGeneSegment();
        chromosome->addGenes(geneSegment);
        delete geneSegment;
    }
    return chromosome;
}

Chromosome* Generator::getRadomGeneSegment() {
    uint8_t genesLength = this->addressLength * 2 + 1;
    Chromosome *chromosome = new Chromosome();
    for (uint8_t i = 0; i < genesLength; i++) {
        chromosome->setGene(this->bernoulliJudge->getRandom());
    }
    return chromosome;
}