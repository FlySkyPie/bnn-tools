#pragma once
#include <set>
#include <cstdint>

class NeuralLinkContainerInterface {
public:

    virtual ~NeuralLinkContainerInterface() {
    }

    virtual void addLink(uint32_t id1 , uint32_t id2 , bool weight ) = 0;
};