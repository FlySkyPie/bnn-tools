#ifndef FLYSKYPIE_BERNOULLIJUDGE_H
#define FLYSKYPIE_BERNOULLIJUDGE_H
#include <cstdint>
#include <random>

class BernoulliJudge {
public:
  BernoulliJudge(float probability);

  bool getRandom();
  float getSuccessRate();

private:
  std::random_device randDevice;
  std::mt19937 * randNumber;
  std::bernoulli_distribution * bernoulli;
  uint64_t success;
  uint64_t fail;
};

#endif