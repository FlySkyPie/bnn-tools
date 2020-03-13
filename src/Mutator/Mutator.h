#ifndef FLYSKYPIE_MUTATOR_H
#define FLYSKYPIE_MUTATOR_H
#include <string>
#include "Chromosome.h"
#include "BernoulliJudge.h"
using namespace std;

class Mutator {
public:
  Mutator(string string);
  Chromosome* getChild();

private:
  float mutationRate;
  uint64_t addressLength;
  Chromosome* subject;
  Chromosome* getMutationRate(float mutationRate);
  Chromosome* getMutatedLength(int length, BernoulliJudge *judge);
  void transcribe(Chromosome * source, Chromosome * target);
};


#endif