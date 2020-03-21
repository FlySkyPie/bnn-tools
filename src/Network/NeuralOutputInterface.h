#pragma once

class NeuralOutputInterface {
public:

    virtual ~NeuralOutputInterface() {
    }

    virtual bool getValue(uint32_t id) = 0;
};