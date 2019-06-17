#include <gtest/gtest.h>
#include "Mutator.h"

#include <string>
using namespace std;

TEST(Mutator, testMutate) {
  string testString = "";
  testString += (char) 0;
  testString += (char) 0x9f;
  testString += (char) 0x50;

  Mutator mutator(testString);

  ASSERT_STREQ("0000000010011111010100000", mutator.getChild()->printBinary().c_str());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}