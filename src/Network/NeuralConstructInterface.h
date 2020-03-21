#pragma once

class NeuralConstructInterface {
public:

    virtual ~NeuralConstructInterface() {
    }

    virtual void addNode(uint32_t id) = 0;
    virtual void addLink(uint32_t id1, uint32_t id2, bool weight) = 0;
};