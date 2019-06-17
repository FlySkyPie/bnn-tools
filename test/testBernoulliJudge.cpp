#include <gtest/gtest.h>

#include "BernoulliJudge.h"

TEST(BernoulliJudge, testProbability_0_0) {
  int success = 0;

  BernoulliJudge judge(0);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(0, success);
}

TEST(BernoulliJudge, testProbability_1_0) {
  int success = 0;

  BernoulliJudge judge(1);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(1000, success);
}

TEST(BernoulliJudge, testProbability_0_5) {
  int success = 0;

  BernoulliJudge judge(0.5);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(5.0, round(success/100.0));
}

TEST(BernoulliJudge, testProbability_0_8) {
  int success = 0;

  BernoulliJudge judge(0.8);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(8.0, round(success/100.0));
}

TEST(BernoulliJudge, testProbability_0_1) {
  int success = 0;

  BernoulliJudge judge(0.1);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(1.0, round(success/100.0));
}

TEST(BernoulliJudge, testGetSuccessRate_0) {
  int success = 0;

  BernoulliJudge judge(0);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(0, judge.getSuccessRate());
}

TEST(BernoulliJudge, testGetSuccessRate_1) {
  int success = 0;

  BernoulliJudge judge(1);

  for (int i = 0; i < 1000; i++) {
    if (judge.getRandom()) {
      success += 1;
    }
  }
  ASSERT_EQ(1, judge.getSuccessRate());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}