#include <gtest/gtest.h>
#include <iostream>

#include "LinkGene.h"
#include "BernoulliJudge.h"

/**
 * genes:
 * 01101000 01101000
 * 
 * translated:
 * 0110 1000 0 1101000
 * 
 */
TEST(LinkGene, testGetMutatedNormal) {
    BernoulliJudge judge(1);
    LinkGene linkGene(4, &judge);
    Chromosome chromosome;
    chromosome.addGenes(0x68);
    chromosome.addGenes(0x68);

    linkGene.loadGenes(&chromosome);

    Chromosome * result = linkGene.getMutatedNormal();

    ASSERT_STREQ("011010000", result->printBinary().c_str());
}

/**
 * genes:
 * 00111100 01101000
 * 
 * translated:
 * 0011 1100 0 1101000
 * 
 * shrinked:
 * 011 100 0 1101000
 * 
 */
TEST(LinkGene, testGetMutatedShrinked) {
    BernoulliJudge judge(1);
    LinkGene linkGene(4, &judge);
    Chromosome chromosome;
    chromosome.addGenes(0x3c);
    chromosome.addGenes(0x68);

    linkGene.loadGenes(&chromosome);

    Chromosome * result = linkGene.getMutatedShrinked();

    ASSERT_STREQ("0111000", result->printBinary().c_str());
}

/**
 * genes:
 * 01101100 01101000
 * 
 * translated:
 * 0110 1100 0 1101000
 */
TEST(LinkGene, testGetMutatedShrinked_When_Give_Middle_Address_In_First_Node_Then_Abandon) {
    BernoulliJudge judge(1);
    LinkGene linkGene(4, &judge);
    Chromosome chromosome;
    chromosome.addGenes(0x6c);
    chromosome.addGenes(0x68);

    linkGene.loadGenes(&chromosome);

    Chromosome * result = linkGene.getMutatedShrinked();

    ASSERT_STREQ("", result->printBinary().c_str());
}

/**
 * genes:
 * 00111000 01101000
 * 
 * translated:
 * 0011 1000 0 1101000
 */
TEST(LinkGene, testGetMutatedShrinked_When_Give_Middle_Address_In_Second_Node_Then_Abandon) {
    BernoulliJudge judge(1);
    LinkGene linkGene(4, &judge);
    Chromosome chromosome;
    chromosome.addGenes(0x38);
    chromosome.addGenes(0x68);

    linkGene.loadGenes(&chromosome);

    Chromosome * result = linkGene.getMutatedShrinked();

    ASSERT_STREQ("", result->printBinary().c_str());
}

/**
 * genes:
 * 00111100 01101000
 * 
 * translated:
 * 0011 1100 0 1101000
 * 
 * extended:
 * 00011 11100 0 1101000
 * 
 */
TEST(LinkGene, testGetMutatedExtended) {
    BernoulliJudge judge(1);
    LinkGene linkGene(4, &judge);
    Chromosome chromosome;
    chromosome.addGenes(0x3c);
    chromosome.addGenes(0x68);

    linkGene.loadGenes(&chromosome);

    Chromosome * result = linkGene.getMutatedExtended();

    ASSERT_STREQ("00011111000", result->printBinary().c_str());
}