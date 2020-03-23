#include "BreakoutActionMaker.h"

BreakoutActionMaker::BreakoutActionMaker(NeuralOutputInterface * neuralOuput)
: AbstractActionMaker(neuralOuput) {
}

BreakoutActionMaker::~BreakoutActionMaker() {
}

/**
 * The definitions of actions are:
 * ['NOOP', 'FIRE', 'RIGHT', 'LEFT']
 * 
 * @return 
 */
uint8_t BreakoutActionMaker::getAction(){
    bool isMove = this->neuralOuput->getValue(0);
    bool direction = this->neuralOuput->getValue(1);
    return (isMove << 1) + direction;
}