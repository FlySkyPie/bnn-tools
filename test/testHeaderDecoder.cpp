#include <gtest/gtest.h>

#include "Chromosome.h"
#include "HeaderDecoder.h"

TEST(HeaderDecoder, testDecodeMutationRate_1) {
  bool test[] = {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0};
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  HeaderDecoder decoder(&chromosome);
  ASSERT_EQ(0.5, decoder.getMutationRate());
}

TEST(HeaderDecoder, testDecodeMutationRate_2) {
  bool test[] = {0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0};
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  HeaderDecoder decoder(&chromosome);
  ASSERT_EQ(0.125, decoder.getMutationRate());
}

TEST(HeaderDecoder, testDecodeAddressLength_1) {
  bool test[] = {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0};
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  HeaderDecoder decoder(&chromosome);
  ASSERT_EQ(4, decoder.getLengthOfNodeAddress());
}

TEST(HeaderDecoder, testDecodeAddressLength_2) {
  bool test[] = {1, 0, 0, 0, 0, 0, 0, 0, 1, 0};
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  HeaderDecoder decoder(&chromosome);
  ASSERT_EQ(2, decoder.getLengthOfNodeAddress());
}