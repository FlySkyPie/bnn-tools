#include <gtest/gtest.h>
#include "Chromosome.h"
#include "StringEncoder.h"
#include <iostream>
#include <string>
using namespace std;

TEST(StringDecoder, testDecode_01100001) {

  bool test[] = {0, 1, 1, 0, 0, 0, 0, 1};
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  StringEncoder encoder;
  string str = encoder.encode(&chromosome);
  ASSERT_STREQ("a", str.c_str());
}
TEST(StringDecoder, testDecode_01001000_miss_3_bit) {

  bool test[] = {0, 1, 0, 0, 1};
  int length = sizeof (test) / sizeof (test[0]);

  Chromosome chromosome;
  for (int i = 0; i < length; i++) {
    chromosome.setGene(test[i]);
  }

  StringEncoder encoder;
  string str = encoder.encode(&chromosome);
  ASSERT_STREQ("H", str.c_str());
}