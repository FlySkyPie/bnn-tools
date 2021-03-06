#include <gtest/gtest.h>

#include "Chromosome.h"

TEST(Chromosome, testAddGenes_FF) {
    Chromosome chromosome;
    chromosome.addGenes(0xff);

    ASSERT_STREQ("11111111", chromosome.printBinary().c_str());
}

TEST(Chromosome, testAddGenes_88) {
    Chromosome chromosome;
    chromosome.addGenes(0x88);

    ASSERT_STREQ("10001000", chromosome.printBinary().c_str());
}

TEST(Chromosome, testAddGenes_ChromosomeGived_FF) {
    Chromosome originalChromosome, targetChromosome;
    originalChromosome.addGenes(0xff);
    targetChromosome.addGenes(&originalChromosome);

    ASSERT_STREQ("11111111", targetChromosome.printBinary().c_str());
}

TEST(Chromosome, testAddGenes_ChromosomeGived_88) {
    Chromosome originalChromosome, targetChromosome;
    originalChromosome.addGenes(0x88);
    targetChromosome.addGenes(&originalChromosome);

    ASSERT_STREQ("10001000", targetChromosome.printBinary().c_str());
}