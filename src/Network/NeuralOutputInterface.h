#pragma once

class NeuralOutputInterface {
public:

    virtual ~NeuralOutputInterface() {
    }

    /**
     * Get output value from Neural network.
     * The id are output id, not neuron id.
     */
    virtual bool getValue(uint32_t id) = 0;
};