#pragma once
#include <set>
#include <cstdint>

class NeuralInputInterface {
public:

    virtual ~NeuralInputInterface() {
    }

    virtual std::set<uint32_t> getInputNodeIds(uint32_t range) = 0;
    virtual void reset() = 0;
    virtual void setValue(uint32_t id, bool value) = 0;

};