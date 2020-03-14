#ifndef FLYSKYPIE_CHROMOSOME_H
#define FLYSKYPIE_CHROMOSOME_H

#include <queue>
#include <string>
using namespace std;

/*
 * Container of genes.
 */
class Chromosome{
public:
  Chromosome();
  ~Chromosome();
  
  void addGenes(uint8_t genes);
  void setGene(bool gene);
  bool getGene(bool & gene);
  Chromosome *getClone();
  Chromosome *getEmpty();
  
  string printBinary();
private:
  queue<bool> genes;

};

#endif