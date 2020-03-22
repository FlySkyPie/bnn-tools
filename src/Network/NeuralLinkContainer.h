#pragma once
#include <map>
#include <utility>
#include <unordered_set>

#include "NeuralLinkContainerInterface.h"
#include "NeuralConstructInterface.h"

class NeuralLinkContainer : public NeuralLinkContainerInterface {
public:
    NeuralLinkContainer();
    virtual ~NeuralLinkContainer();

    void addLink(uint32_t id1, uint32_t id2, bool weight);
    void construct(NeuralConstructInterface* neural);
private:
    std::multimap <uint32_t, std::pair <uint32_t, bool> > linkMap;
    std::unordered_set<uint32_t> nodeSet;
};

