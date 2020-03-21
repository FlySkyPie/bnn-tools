#pragma once

class NeuralConstructInterface {
public:

    virtual ~NeuralConstructInterface() {
    }

    /**
     * To creating nodes.
     * 
     * @param id
     */
    virtual void addNode(uint32_t id) = 0;
    
    /**
     * Add link between two nodes, 
     * make sure node have been created before linking.
     * 
     * @param id1
     * @param id2
     * @param weight
     */
    virtual void addLink(uint32_t id1, uint32_t id2, bool weight) = 0;
};