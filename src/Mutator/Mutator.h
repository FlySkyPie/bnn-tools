#pragma once
#include <string>
#include "Chromosome.h"
#include "BernoulliJudge.h"
#include "LinkGene.h"

using namespace std;

/**
 * The mutator to generate next generation of chromosome.
 */

class Mutator {
public:
    Mutator();
    ~Mutator();

    Mutator* setInverseJudge(BernoulliJudge* judge);
    Mutator* setVaryJudge(BernoulliJudge* judge);
    Mutator* setChromosome(Chromosome* chromosome);
    Mutator* setAddressLength(uint64_t length);

    Chromosome* getChild();

private:
    /**
     * For mutate genes.
     */
    BernoulliJudge* inverseJudge;

    /**
     * For extend/shrink and deletion/duplication.
     */
    BernoulliJudge* varyJudge;

    /**
     * The chromosome of parent.
     */
    Chromosome* subject;

    /**
     * Length of addressing space.
     */
    uint64_t addressLength;

    bool isVary;
    
    bool isExtended;

    bool isReady();
    
     Chromosome * getSegment(LinkGene* linkGene);
};