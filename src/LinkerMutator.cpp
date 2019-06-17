#include "LinkerMutator.h"

LinkerMutator::LinkerMutator() {

}

/*
 * It wouldn't erase source chromosome.
 */
Chromosome * LinkerMutator::getNextGeneration(
        uint64_t length,
        BernoulliJudge * judge,
        Chromosome * source) {
  this->addressLength = length;
  this->judge = judge;

  Chromosome * temp = source->getEmpty();

  this->transcribeLinks(source->getClone(), temp);
  return temp;

}



/*
 * Transcribe genes from source to target, but mutation happened.
 */
void LinkerMutator::transcribeWithMutation(Chromosome * source, Chromosome * target) {
  bool b;
  while (source->getGene(b)) {
    b = (this->judge->getRandom()) ? !b : b;
    target->setGene(b);
  }
}

/*
 * Transcribe a part of gene which describe a link from source to target,
 * but deletion, duplication and  error would happened.
 */
void LinkerMutator::transcribeMutatedLink(Chromosome * source, Chromosome * target) {
  bool deletion, duplication;
  deletion = this->judge->getRandom();
  duplication = this->judge->getRandom();
  if (deletion && !duplication) {
    return;
  }

  if (!deletion && duplication) {
    Chromosome * twice = source->getClone();
    this->transcribeWithMutation(twice, target);
  }

  this->transcribeWithMutation(source, target);
}

/*
 * Transcribe whole link gene from source to target,
 * and mutation would happened.
 */
void LinkerMutator::transcribeLinks(Chromosome * source, Chromosome * target) {
  bool isNoEmpty = 1;
  while (isNoEmpty) {
    Chromosome * tempLink = source->getEmpty();

    isNoEmpty = this->readLink(source, tempLink);

    this->transcribeMutatedLink(tempLink, target);
  }
}

/*
 * Read out a part of gene which describe a link.
 */
bool LinkerMutator::readLink(Chromosome * source, Chromosome * target) {
  bool isNoEmpty;

  for (int i = 0; i < (2 * this->addressLength + 1); i++) {
    bool data;
    isNoEmpty = source->getGene(data);

    if (i == 0 && !isNoEmpty) {
      return 0;
    }

    target->setGene(data);
  }

  return isNoEmpty;
}