#ifndef FLYSKYPIE_STRINGDECODER_H
#define FLYSKYPIE_STRINGDECODER_H
#include "Chromosome.h"
#include <string>
using namespace std;

class StringDecoder {
public:
  StringDecoder();

  Chromosome * decode(string string);
private:
  void writeCharToChromosome(char source,Chromosome* target);

};

#endif