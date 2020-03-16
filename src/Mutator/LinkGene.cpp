#include "LinkGene.h"
#include <iostream> //test

LinkGene::LinkGene(uint8_t addressLength, BernoulliJudge *judge) {
    this->addressLength = addressLength;
    this->judge = judge;
}

LinkGene::~LinkGene() {
    delete this->node1Genes;
    delete this->node2Genes;
}

bool LinkGene::loadGenes(Chromosome* chromosome) {
    if (!this->loadNode1Genes(chromosome)) {
        return 0;
    }

    if (!this->loadNode2Genes(chromosome)) {
        return 0;
    }

    if (!this->loadWeight(chromosome)) {
        return 0;
    }

    return 1;
}

Chromosome* LinkGene::getMutatedNormal() {
    Chromosome *source = this->getNormal();
    Chromosome *target = this->getMutated(source);

    delete source;
    return target;
}

Chromosome* LinkGene::getMutatedShrinked() {
    Chromosome *source = this->getShrinked();
    Chromosome *target = this->getMutated(source);

    delete source;
    return target;
}

Chromosome* LinkGene::getMutatedExtended() {
    Chromosome *source = this->getExtended();
    Chromosome *target = this->getMutated(source);

    delete source;
    return target;
}

void LinkGene::transcribeMutated(BernoulliJudge *judge,
        Chromosome* source, Chromosome* target) {
    bool gene;
    source->getGene(gene);
    gene = judge->getRandom() ? gene : ~gene;
    target->setGene(gene);
}

bool LinkGene::loadNode1Genes(Chromosome* chromosome) {
    this->node1Genes = new Chromosome;

    bool gene;
    for (uint32_t i = 0; i<this->addressLength; i++) {
        if (!chromosome->getGene(gene)) {
            return 0;
        }
        this->node1Genes->setGene(gene);
    }

    return 1;
}

bool LinkGene::loadNode2Genes(Chromosome* chromosome) {
    this->node2Genes = new Chromosome;

    bool gene;
    for (uint32_t i = 0; i<this->addressLength; i++) {
        if (!chromosome->getGene(gene)) {
            return 0;
        }
        this->node2Genes->setGene(gene);
    }

    return 1;
}

bool LinkGene::loadWeight(Chromosome* chromosome) {
    bool gene;

    if (!chromosome->getGene(gene)) {
        return 0;
    }
    this->weight = gene;

    return 1;
}

Chromosome* LinkGene::getMutated(Chromosome* chromosome) {
    Chromosome* source = chromosome->getClone();
    Chromosome* target = new Chromosome();

    bool gene;
    while (source->getGene(gene)) {
        gene = this->judge->getRandom() ? gene : ~gene;
        target->setGene(gene);
    }
    delete source;
    return target;
}

Chromosome* LinkGene::getNormal() {
    Chromosome* source;
    Chromosome* target = new Chromosome();
    source = this->node1Genes->getClone();
    target->addGenes(source);
    delete source;
    source = this->node2Genes->getClone();
    target->addGenes(source);
    delete source;
    target->setGene(this->weight);
    return target;
}

/**
 * Remove 50% of node which addressing at middle.
 * 
 * @return 
 */
Chromosome* LinkGene::getShrinked() {
    if (this->addressLength <= 1) {
        return this->getNormal();
    }
    Chromosome* node1 = this->node1Genes->getClone();
    Chromosome* node2 = this->node2Genes->getClone();
    bool node1_1, node1_2, node2_1, node2_2;

    node1->getGene(node1_1);
    node1->getGene(node1_2);

    node2->getGene(node2_1);
    node2->getGene(node2_2);

    if (node1_1 != node1_2 || node2_1 != node2_2) {
        return new Chromosome();
    }

    Chromosome* target = new Chromosome();
    target->setGene(node1_1);
    target->addGenes(node1);

    target->setGene(node2_1);
    target->addGenes(node2);
    target->setGene(this->weight);

    delete node1;
    delete node2;
    return target;
}

Chromosome* LinkGene::getExtended() {
    Chromosome* node1 = this->node1Genes->getClone();
    Chromosome* node2 = this->node2Genes->getClone();
    bool node1_1, node2_1;

    node1->getGene(node1_1);
    node2->getGene(node2_1);

    Chromosome* target = new Chromosome();
    target->setGene(node1_1);
    target->setGene(node1_1);
    target->addGenes(node1);
    target->setGene(node2_1);
    target->setGene(node2_1);
    target->addGenes(node2);
    target->setGene(this->weight);

    delete node1;
    delete node2;
    return target;
}