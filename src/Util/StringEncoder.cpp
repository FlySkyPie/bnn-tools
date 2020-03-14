#include "StringEncoder.h"

StringEncoder::StringEncoder() {


}

string StringEncoder::encode(Chromosome * chromosome) {
  string str = "";
  bool isNoEmpty = 1;
  while (isNoEmpty) {
    char c = 0;

    isNoEmpty = readChromosomeToChar(chromosome, &c);
    str += c;
  }
  return str;
}

bool StringEncoder::readChromosomeToChar(Chromosome * source, char* c) {
  bool isNoEmpty;

  for (int i = 0; i < 8; i++) {
    bool data;
    isNoEmpty = source->getGene(data);

    if (i == 0 && !isNoEmpty) {
      return 0;
    }
    *c <<= 1;
    *c += data ? 1 : 0;
  }

  return isNoEmpty;
}
