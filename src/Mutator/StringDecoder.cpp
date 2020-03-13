#include "StringDecoder.h"

StringDecoder::StringDecoder() {
}

Chromosome * StringDecoder::decode(string string) {
  Chromosome * chromosome = new Chromosome();

  while (string.size()) {
    char c = string.at(0);
    this->writeCharToChromosome(c, chromosome);
    string.erase(0,1);
  }
  return chromosome;

}

void StringDecoder::writeCharToChromosome(char source, Chromosome* target) {
  for (int i = 7; i >= 0; i--) {
    target->setGene((source >> i) % 2); 
  }
}