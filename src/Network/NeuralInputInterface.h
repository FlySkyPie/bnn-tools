#pragma once
#include <set>
#include <cstdint>

class NeuralInputInterface {
public:

    virtual ~NeuralInputInterface() {
    }

    /**
     * Get nodes are existed which id within 0 to range.
     * 
     * @param range
     * @return 
     */
    virtual std::set<uint32_t> getInputNodeIds(uint32_t range) = 0;
    
    /**
     * Reset all neurons in neural network,
     * to prepared updates neuron.
     */
    virtual void reset() = 0;
    
    /**
     * Set value to certain neuron.
     * 
     * @param id
     * @param value
     */
    virtual void setValue(uint32_t id, bool value) = 0;

};