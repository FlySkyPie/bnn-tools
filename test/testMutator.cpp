#include <gtest/gtest.h>
#include "Mutator.h"
#include "BernoulliJudge.h"
#include "Chromosome.h"

/**
 * genes:
 * 01101000 01101000
 * 
 * translated:
 * 0110 1000 0 1101000
 * 
 */
TEST(Mutator, testGetChild_With_100_Successed) {
    BernoulliJudge judge(1);
    Mutator mutator;
    Chromosome chromosome;
    chromosome.addGenes(0x68);
    chromosome.addGenes(0x68);

    mutator.setAddressLength(4)
            ->setInverseJudge(&judge)
            ->setVaryJudge(&judge)
            ->setChromosome(&chromosome);

    Chromosome * result = mutator.getChild();

    ASSERT_STREQ("011010000", result->printBinary().c_str());
}