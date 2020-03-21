#include <cmath>

#include "NeuralChamber.h"
#include "Neuron.h"

NeuralChamber::NeuralChamber(uint8_t addressingLength) {
    this->maxId = std::pow(2, addressingLength) - 1;
}

NeuralChamber::~NeuralChamber() {
}

bool NeuralChamber::getValue(uint32_t id) {
    uint32_t outputId = (this->maxId) - id;
    return outputId;
}

std::set<uint32_t> NeuralChamber::getInputNodeIds(uint32_t range) {
    std::set<uint32_t> newSet;
    for (auto it = this->neuronIds.begin(); it != this->neuronIds.end(); ++it) {
        if ((*it) > range) {
            break;
        }
        newSet.insert((*it));
    }
    return newSet;
}

void NeuralChamber::reset() {
    for (std::unordered_map<uint32_t, Neuron>::iterator it = this->neurons.begin(); it != this->neurons.end(); ++it) {
        Neuron * node = &(it->second);
        node->reset();
    }
}

void NeuralChamber::setValue(uint32_t id, bool value) {
    auto iterator = this->neurons.find(id);
    if (iterator == this->neurons.end()) {
        //throw except
    }
    Neuron * node = &(iterator->second);
    node->setValue(value);
}

void NeuralChamber::addNode(uint32_t id) {
    this->neurons.emplace(id, id);
    this->neuronIds.insert(id);
}

void NeuralChamber::addLink(uint32_t id1, uint32_t id2, bool weight) {
    auto iterator1 = this->neurons.find(id1);
    auto iterator2 = this->neurons.find(id2);
    if (iterator1 == this->neurons.end() || iterator2 == this->neurons.end()) {
        //throw except
    }
    Neuron * node1 = &(iterator1->second);
    Neuron * node2 = &(iterator2->second);
    node1->addSubNodes(node2, weight);
}