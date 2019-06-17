#include <gtest/gtest.h>
#include "Chromosome.h"
#include "StringDecoder.h"
#include <iostream>
#include <string>
using namespace std;

TEST(StringDecoder, testDecode_aa) {
  string test = "aa";
  StringDecoder decoder;
  
  Chromosome *chromosome = decoder.decode(test);
  
  ASSERT_STREQ("0110000101100001", chromosome->printBinary().c_str());
}

TEST(StringDecoder, testDecode_ooo) {
  string test = "ooo";
  StringDecoder decoder;
  
  Chromosome *chromosome = decoder.decode(test);
  
  ASSERT_STREQ("011011110110111101101111", chromosome->printBinary().c_str());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}