#ifndef FLYSKYPIE_HEADERDECODER_H
#define FLYSKYPIE_HEADERDECODER_H
#include "Chromosome.h"
#include <cstdint>

class HeaderDecoder {
public:
  HeaderDecoder(Chromosome * chromosome);

  float getMutationRate();
  uint32_t getLengthOfNodeAddress();
private:
  Chromosome * chromosome;
  float floatProbability;
  uint32_t lengthOfNodeAddress;

  void decodeProbability(Chromosome * chromosome);
  void decodeAddressLength(Chromosome * chromosome);
};
#endif