#pragma once

#include <cstdint>
#include <unordered_map>
#include <set>

#include "Neuron.h"
#include "NeuralConstructInterface.h"
#include "NeuralInputInterface.h"
#include "NeuralOutputInterface.h"

class NeuralChamber : public NeuralConstructInterface,
public NeuralInputInterface, public NeuralOutputInterface {
public:
    NeuralChamber(uint8_t addressingLength);
    virtual ~NeuralChamber();

    void addNode(uint32_t id);
    void addLink(uint32_t id1, uint32_t id2, bool weight);

    std::set<uint32_t> getInputNodeIds(uint32_t range);
    void reset();
    void setValue(uint32_t id, bool value);

    bool getValue(uint32_t id);
private:
    std::unordered_map<uint32_t, Neuron> neurons;
    std::set<uint32_t> neuronIds;
    uint32_t maxId;

};