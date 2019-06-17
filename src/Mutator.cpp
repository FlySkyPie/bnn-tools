#include "Mutator.h"
#include "StringDecoder.h"
#include "HeaderDecoder.h"

#include "LinkerMutator.h"

/*
 * Decode string, and storage gene information in it.
 */
Mutator::Mutator(string string) {
  StringDecoder decoder;
  Chromosome * chromosome = decoder.decode(string);
  HeaderDecoder header(chromosome);

  this->mutationRate = header.getMutationRate();
  this->addressLength = header.getLengthOfNodeAddress();
  this->subject = chromosome;
}

/*
 * Generate mutated child chromosome.
 */
Chromosome* Mutator::getChild() {
  BernoulliJudge judge(this->mutationRate);

  Chromosome * mutatedLength = this->getMutatedLength(
          this->addressLength,
          &judge);
  LinkerMutator mutator;
  Chromosome * childLinker = mutator.getNextGeneration(
          this->addressLength,
          &judge,
          this->subject->getClone());
  Chromosome * mutationRateGene = this->getMutationRate(judge.getSuccessRate());

  this->transcribe(mutatedLength, mutationRateGene);
  this->transcribe(childLinker, mutationRateGene);
  return mutationRateGene;
}

/*
 * Get mutated address length, and transform to chromosome.
 */
Chromosome* Mutator::getMutatedLength(int length, BernoulliJudge *judge) {
  Chromosome* chromosome = new Chromosome();

  bool increase, decrease;
  increase = judge->getRandom();
  decrease = judge->getRandom();

  if (increase && !decrease) {
    length += 1;
  } else if (!increase && decrease) {
    length -= 1;
  }

  for (int i = 1; i < length; i++) {
    chromosome->setGene(1);
  }
  chromosome->setGene(0);
  return chromosome;

}

/*
 * Translate mutation rate to chromosome.
 */
Chromosome* Mutator::getMutationRate(float mutationRate) {
  Chromosome* chromosome = new Chromosome();

  for (int i = 0; i < 8; i++) {
    mutationRate *= 2;
    if (mutationRate >= 1) {
      mutationRate -= 1;
      chromosome->setGene(1);
    } else {
      chromosome->setGene(0);
    }
  }
  return chromosome;
}

/*
 * Transcribe genes from source to target.
 */
void Mutator::transcribe(Chromosome * source, Chromosome * target) {
  bool b;
  while (source->getGene(b)) {
    target->setGene(b);
  }
}