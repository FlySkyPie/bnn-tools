#include <gtest/gtest.h>
#include "Chromosome.h"
#include "LinkerMutator.h"
#include "BernoulliJudge.h"
#include "HeaderDecoder.h"

TEST(LinkerMutator, testGetNextGeneration_0_mutation_rate) {
  bool test[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1
  };
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  HeaderDecoder decoder(&chromosome);
  BernoulliJudge judge(decoder.getMutationRate());
  LinkerMutator mutator;

  Chromosome *next = mutator.getNextGeneration(decoder.getLengthOfNodeAddress(), &judge, &chromosome);

  ASSERT_STREQ(chromosome.printBinary().c_str(), next->printBinary().c_str());
}

TEST(LinkerMutator, testGetNextGeneration_0_5_mutation_rate) {
  bool test[] = {
    1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1,
    0, 1, 1, 1, 1
  };
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  HeaderDecoder decoder(&chromosome);
  BernoulliJudge judge(decoder.getMutationRate());
  LinkerMutator mutator;

  Chromosome *next = mutator.getNextGeneration(decoder.getLengthOfNodeAddress(), &judge, &chromosome);

  ASSERT_STRNE(chromosome.printBinary().c_str(), next->printBinary().c_str());
}