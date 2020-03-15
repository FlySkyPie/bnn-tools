#include <gtest/gtest.h>
#include <iostream>
#include "Decoder.h"
#include "Chromosome.h"

/**
 * genes:
 * 00001100 01101000 01101000 01101000 01101000
 * 
 * translated:
 * 00001100 011010000110 100001101000 0 1101000
 * 12       1670         2152         0 -------
 */
TEST(Decoder, testConvertToJson) {
    Decoder decoder;
    Chromosome chromosome;
    chromosome.addGenes(12);
    chromosome.addGenes(0x68);
    chromosome.addGenes(0x68);
    chromosome.addGenes(0x68);
    chromosome.addGenes(0x68);

    std::string jsonString = "{\"address-length\":12,\"links\":[[1670,2152,false]]}";

    ASSERT_STREQ(decoder.convertToJson(&chromosome).c_str(), jsonString.c_str());
}