#include "Chromosome.h"
#include <cstdint>
#include <iostream>

Chromosome::Chromosome() {

}

Chromosome::~Chromosome() {
}

/**
 * Add genes from a Chromosome to the Chromosome.
 * 
 * @param genes
 */
void Chromosome::addGenes(Chromosome * originalChromosome) {
    Chromosome* chromosome = originalChromosome->getClone();
    bool gene;
    while (chromosome->getGene(gene)) {
        this->genes.push(gene);
    }
}

/**
 * Add a byte of genes to chromosome.
 * 
 * @param genes
 */
void Chromosome::addGenes(uint8_t genes) {
    for (uint8_t i = 0; i < 8; i++) {
        uint8_t shift = 7 - i;
        bool gene = (genes >> shift) & 1;
        this->genes.push(gene);
    }
}

/*
 * Write a bit of gene to the chromosome.
 */
void Chromosome::setGene(bool gene) {
    this->genes.push(gene);
}

/*
 * Get a gene data, it'll return true when there still have genes.
 * If there are no enough of gene, gave 0.
 * Return status of stock, 0 means chromosome empty.
 */
bool Chromosome::getGene(bool & gene) {
    if (!this->genes.size()) {
        gene = 0;
        return 0;
    }
    gene = this->genes.front();
    this->genes.pop();
    return 1;
}

/*
 * Clone the chromosome, it'll copy whole genes.
 */
Chromosome *Chromosome::getClone() {
    Chromosome *cloneChromosome = new Chromosome();
    uint32_t length = this->genes.size();

    for (uint32_t i = 0; i < length; i++) {
        bool gene = this->genes.front();
        this->genes.push(gene);
        this->genes.pop();
        cloneChromosome->setGene(gene);
    }

    return cloneChromosome;
}

/*
 * Create new empty chromosome.
 */
Chromosome *Chromosome::getEmpty() {
    return new Chromosome;
}

string Chromosome::printBinary() {
    string str = "";
    uint32_t length = this->genes.size();

    for (uint32_t i = 0; i < length; i++) {
        bool gene = this->genes.front();
        str += gene ? "1" : "0";
        this->genes.push(gene);
        this->genes.pop();
    }
    return str;
}