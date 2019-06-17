#ifndef FLYSKYPIE_STRINGENCODER_H
#define FLYSKYPIE_STRINGENCODER_H

#include "Chromosome.h"
#include <string>
using namespace std;
class StringEncoder {
public:
  StringEncoder();
  string encode(Chromosome * chromosome);

private:
  bool readChromosomeToChar(Chromosome * source,char* c);
 
};

#endif