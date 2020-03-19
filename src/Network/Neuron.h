#pragma once

#include <list>
#include <cstdint>

class Neuron {
public:
    Neuron(uint32_t id);
    virtual ~Neuron();

    void addSubNodes(Neuron* node, bool weight);
    void reset();
    void setValue(bool value);
    bool getValue(uint32_t id);

private:
    uint32_t id;
    bool isComputed;
    bool currentValue;
    bool lastValue;
    std::list<Neuron*> subNodes;
    std::list<bool> weights;

    void compute();
};