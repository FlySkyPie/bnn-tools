#include "BernoulliJudge.h"

BernoulliJudge::BernoulliJudge(float probability) {
  this->randNumber = new std::mt19937(this->randDevice());
  this->bernoulli = new std::bernoulli_distribution(probability);

  this->success = 0;
  this->fail = 0;
}

bool BernoulliJudge::getRandom() {
  bool result = this->bernoulli->operator()(*this->randNumber);
  if (result) {
    this->success += 1;
  } else {
    this->fail += 1;
  }
  return result;
}

float BernoulliJudge::getSuccessRate() {
  return (float) (this->success) / (this->success + this->fail);
}