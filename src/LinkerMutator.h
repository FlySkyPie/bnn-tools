#ifndef FLYSKYPIE_LINKERMUTATOR_H
#define FLYSKYPIE_LINKERMUTATOR_H
#include <cstdint>

#include "BernoulliJudge.h"
#include "Chromosome.h"

class LinkerMutator {
public:
  LinkerMutator();
  Chromosome * getNextGeneration(uint64_t length, BernoulliJudge * judge, Chromosome * source);

private:
  
  void transcribeWithMutation(Chromosome * source, Chromosome * target);
  void transcribeMutatedLink(Chromosome * source, Chromosome * target);
  void transcribeLinks(Chromosome * source, Chromosome * target);
  bool readLink(Chromosome * source, Chromosome * target);


  uint64_t addressLength;
  BernoulliJudge * judge;
  Chromosome * subject;
};
#endif