#include <stdexcept>

#include "Mutator.h"
#include "LinkGene.h"

/*
 * Decode string, and storage gene information in it.
 */
Mutator::Mutator() {
    this->inverseJudge = nullptr;
    this->varyJudge = nullptr;
    this->subject = nullptr;
    this->addressLength = 0;
}

Mutator::~Mutator() {
    delete this->subject;
}

Mutator* Mutator::setInverseJudge(BernoulliJudge* judge) {
    this->inverseJudge = judge;
    return this;
}

Mutator* Mutator::setVaryJudge(BernoulliJudge* judge) {
    this->varyJudge = judge;
    return this;
}

Mutator* Mutator::setChromosome(Chromosome* chromosome) {
    if (this->subject) {
        delete this->subject;
    }

    this->subject = chromosome->getClone();
    return this;
}

Mutator* Mutator::setAddressLength(uint8_t length) {
    this->addressLength = length;
    return this;
}

/*
 * Generate mutated child chromosome.
 */
Chromosome* Mutator::getChild() {
    if (!this->isReady()) {
        throw std::runtime_error(
                "Something missing, "
                "make sure you had setting all necessary stuff for mutator.");
    }

    Chromosome * source = this->subject->getClone();
    Chromosome * child = new Chromosome();
    uint8_t newLength = this->addressLength;

    this->isVary = !(this->inverseJudge->getRandom());
    this->isExtended = this->varyJudge->getRandom();
    
     if (this->isVary) {
         newLength = (this->isExtended)? newLength +1 : newLength-1;
     }

    child->addGenes(newLength);

    while (1) {
        LinkGene processor(this->addressLength, this->inverseJudge);
        if (!processor.loadGenes(source)) {
            break;
        }

        Chromosome * segment;
        bool isSegmentMutated = !(this->inverseJudge->getRandom());
        if (!isSegmentMutated) {
            segment = this->getSegment(&processor);
            child->addGenes(segment);
            delete segment;
            continue;
        }

        bool isDuplication = this->varyJudge->getRandom();
        if (isDuplication) {
            segment = this->getSegment(&processor);
            segment->addGenes(segment);
            child->addGenes(segment);
            delete segment;
        }
    }

    return child;
}

/**
 * Checking the mutator is ready to work.
 * 
 * @return bool
 */
bool Mutator::isReady() {
    if (!this->inverseJudge) {
        return false;
    }
    if (!this->varyJudge) {
        return false;
    }
    if (!this->subject) {
        return false;
    }
    if (this->addressLength == 0) {
        return false;
    }
    return true;
}

Chromosome * Mutator::getSegment(LinkGene* linkGene) {
    if (this->isVary) {
        return (this->isExtended) ?
                linkGene->getMutatedExtended() :
                linkGene->getMutatedShrinked();
    } else {
        return linkGene->getMutatedNormal();
    }
}