#include "AbstractActionMaker.h"

AbstractActionMaker::AbstractActionMaker(NeuralOutputInterface * neuralOuput) {
    this->neuralOuput = neuralOuput;
}

AbstractActionMaker::~AbstractActionMaker() {
}

