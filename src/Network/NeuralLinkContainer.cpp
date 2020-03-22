#include "NeuralLinkContainer.h"

NeuralLinkContainer::NeuralLinkContainer() {
}

NeuralLinkContainer::~NeuralLinkContainer() {
}

/**
 * Record nodes and links by linking given,
 * should ignore repeated nodes and links.
 * 
 * @param id1
 * @param id2
 * @param weight
 */
void NeuralLinkContainer::addLink(uint32_t id1, uint32_t id2, bool weight) {
    this->nodeSet.insert(id1);
    this->nodeSet.insert(id2);

    auto referenceIterator = this->linkMap.equal_range(id1);
    for (auto it = referenceIterator.first; it != referenceIterator.second; ++it){
        auto pair = it->second;
        if(pair.first == id2 && pair.second == weight){
            return;
        }
    }
    this->linkMap.insert(std::make_pair(id1, std::make_pair(id2, weight)));
}

void NeuralLinkContainer::construct(NeuralConstructInterface* neural) {
    //register nods
    for (auto it = this->nodeSet.begin(); it != this->nodeSet.end(); ++it) {
        neural->addNode(*it);
    }

    //register links
    for (auto it = this->linkMap.begin(); it != this->linkMap.end(); ++it) {
        uint32_t id1 = it->first;
        uint32_t id2 = it->second.first;
        bool weight = it->second.second;
        neural->addLink(id1, id2, weight);
    }
}

