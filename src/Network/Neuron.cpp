#include "Neuron.h"

Neuron::Neuron(uint32_t id) {
    this->id = id;
    this->isComputed = false;
    this->currentValue = 0;
    this->lastValue = 0;
}

Neuron::~Neuron() {
}

void Neuron::addSubNodes(Neuron* node, bool weight) {
    this->subNodes.push_back(node);
    this->weights.push_back(weight);
}

void Neuron::reset() {
    this->isComputed = false;
    this->lastValue = this->currentValue;
}

void Neuron::setValue(bool value) {
    this->currentValue = value;
    this->isComputed = true;
}

bool Neuron::getValue(uint32_t id) {
    if (id <= this->id) {
        return this->lastValue;
    }
    if (!this->isComputed) {
        this->compute();
    }
    return this->currentValue;
}

void Neuron::compute() {
    this->isComputed = true;

    std::list<Neuron*>::iterator subNodesIterator = this->subNodes.begin();
    std::list<bool>::iterator weightsIterator = this->weights.begin();
    std::list<bool>::iterator endPoint = this->weights.end();

    if (weightsIterator == endPoint) {
        this->currentValue = false;
        return;
    }

    bool result = true;
    while (weightsIterator != endPoint) {
        result = result & ((*subNodesIterator)->getValue(this->id) ^ *weightsIterator);
        ++weightsIterator;
        ++subNodesIterator;
    }
    this->currentValue = result;
}