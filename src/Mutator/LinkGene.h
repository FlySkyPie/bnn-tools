#pragma once
#include <cstdint>

#include "Chromosome.h"
#include "BernoulliJudge.h"

class LinkGene {
public:
    LinkGene(uint8_t addressLength, BernoulliJudge *judge);
    virtual ~LinkGene();
    bool loadGenes(Chromosome* chromosome);

    Chromosome* getMutatedNormal();
    Chromosome* getMutatedShrinked();
    Chromosome* getMutatedExtended();

private:
    uint8_t addressLength;
    BernoulliJudge *judge;
    Chromosome* node1Genes;
    Chromosome* node2Genes;
    bool weight;

    void transcribeMutated(BernoulliJudge *judge, Chromosome* source, Chromosome* target);
    bool loadNode1Genes(Chromosome* chromosome);
    bool loadNode2Genes(Chromosome* chromosome);
    bool loadWeight(Chromosome* chromosome);

    Chromosome* getMutated(Chromosome* chromosome);
    Chromosome* getNormal();
    Chromosome* getShrinked();
    Chromosome* getExtended();
};