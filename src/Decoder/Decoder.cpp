#include <json.hpp> 
#include <iostream>
#include <string>
#include <exception>

#include "Decoder.h"
#include "Chromosome.h"

using json = nlohmann::json;

Decoder::Decoder() {
}

Decoder::~Decoder() {
}

/**
 * Decoding genes in the chromosome to Json string.
 * 
 * @param chromosome
 * @return 
 */
std::string Decoder::convertToJson(Chromosome* chromosome) {
    this->addressLength = this->readAddressLength(chromosome);
    json json;

    json["address-length"] =  this->addressLength;
    json["links"] = {};
    while (1) {
        uint32_t nodeAddress1, nodeAddress2;
        bool gene;

        if (!this->readGeneSegment(chromosome, nodeAddress1, nodeAddress2, gene)) {
            break;
        }
        json["links"] +={nodeAddress1,  nodeAddress2, gene};
    }

    return json.dump();
}

/**
 * Read first 1 byte as addressing length from head of chromosome.
 * 
 * @param chromosome
 * @return 
 */
uint8_t Decoder::readAddressLength(Chromosome* chromosome) {
    uint8_t value = 0;
    for (uint8_t i = 0; i < 8; i++) {
        bool gene;
        if (!chromosome->getGene(gene)) {
            throw "Parse addressing length error occurred.";
        }
        value = (value << 1) | gene;
    }
    return value;
}

/**
 * Read gene segment which described a linking.
 * 
 * @param chromosome
 * @param nodeAddress1
 * @param nodeAddress2
 * @param gene
 * @return 
 */
bool Decoder::readGeneSegment(Chromosome* chromosome,
        uint32_t &nodeAddress1, uint32_t &nodeAddress2, bool &gene) {

    if (!this->readAddress(chromosome, nodeAddress1)) {
        return 0;
    }

    if (!this->readAddress(chromosome, nodeAddress2)) {
        return 0;
    }

    if (!chromosome->getGene(gene)) {
        return 0;
    }
    return 1;
}

/**
 * Read gene segment which described address of node.
 * 
 * @param chromosome
 * @param nodeAddress
 * @return 
 */
bool Decoder::readAddress(Chromosome* chromosome, uint32_t &nodeAddress) {
    uint32_t value = 0;
    for (uint8_t i = 0; i < this->addressLength; i++) {
        bool gene;
        if (!chromosome->getGene(gene)) {
            return 0;
        }
        value = (value << 1) | gene;
    }
    nodeAddress = value;
    return 1;
}