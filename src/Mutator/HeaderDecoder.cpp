#include "HeaderDecoder.h"

HeaderDecoder::HeaderDecoder(Chromosome * chromosome) {
  this->decodeProbability(chromosome);
  this->decodeAddressLength(chromosome);
}

float HeaderDecoder::getMutationRate() {
  return this->floatProbability;
}

uint32_t HeaderDecoder::getLengthOfNodeAddress() {
  return this->lengthOfNodeAddress;
}

void HeaderDecoder::decodeProbability(Chromosome * chromosome) {
  float probability = 0;
  for (int i = 0; i < 8; i++) {
    bool b;
    chromosome->getGene(b);
    if (!b) {
      continue;
    }
    probability += 1.0 / (2 << i);
  }
  this->floatProbability = probability;
}

void HeaderDecoder::decodeAddressLength(Chromosome * chromosome) {
  uint32_t count = 0;
  while (1) {
    count += 1;
    bool b;
    chromosome->getGene(b);
    if (!b) {
      break;
    }
  }

  this->lengthOfNodeAddress = count;
}