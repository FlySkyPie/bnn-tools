#pragma once

#include <cstdint>
#include "AbstractActionMaker.h"

class BreakoutActionMaker : public AbstractActionMaker {
public:
    BreakoutActionMaker(NeuralOutputInterface * neuralOuput);

    virtual ~BreakoutActionMaker();
    
    uint8_t getAction();
private:

};
