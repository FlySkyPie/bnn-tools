#pragma once
#include "NeuralOutputInterface.h"

class AbstractActionMaker {
public:
    AbstractActionMaker(NeuralOutputInterface * neuralOuput);
    virtual ~AbstractActionMaker();
protected:
    NeuralOutputInterface * neuralOuput;
};
