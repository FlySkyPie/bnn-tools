#include <gtest/gtest.h>

#include "Generator.h"

TEST(Generator, testGetChromosome_When_Give_2_4_Then_LengthIs_28) {
    /*
    8 + (2*2+1)*4=28 
    /**/
    Generator g(2,4);

    ASSERT_EQ(28, g.getChromosome()->printBinary().length());
}


TEST(Generator, testGetChromosome_When_Give_10_100_Then_LengthIs_2108) {
    /*
    8 + (2*10+1)*100=2108
    /**/
    Generator g(10,100);

    ASSERT_EQ(2108, g.getChromosome()->printBinary().length());
}

TEST(Generator, testGetChromosome_When_Give_12_2000_Then_LengthIs_50008) {
    /*
    8 + (2*12+1)*2000=2108
    /**/
    Generator g(12,2000);

    ASSERT_EQ(50008, g.getChromosome()->printBinary().length());
}

TEST(Generator, testGetChromosome_When_Give_19_524288_Then_LengthIs_20447240) {
    /*
    8 + (2*19+1)*524288=20447240
    /**/
    Generator g(19,524288);

    ASSERT_EQ(20447240, g.getChromosome()->printBinary().length());
}