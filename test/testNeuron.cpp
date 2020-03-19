#include <gtest/gtest.h>

#include "Neuron.h"

TEST(Neuron, testGetValue_With_No_Subnodes) {
    Neuron neuron(12);

    ASSERT_EQ(0, neuron.getValue(INT32_MAX));
}

TEST(Neuron, testGetValue_0_Xor_0) {
    Neuron neuron1(0);
    Neuron neuron2(1);
    neuron2.addSubNodes(&neuron1, 0);

    ASSERT_EQ(0, neuron2.getValue(INT32_MAX));
}

TEST(Neuron, testGetValue_1_Xor_0) {
    Neuron neuron1(0);
    Neuron neuron2(1);
    neuron2.addSubNodes(&neuron1, 0);
    neuron1.setValue(1);

    ASSERT_EQ(1, neuron2.getValue(INT32_MAX));
}

TEST(Neuron, testGetValue_When_Subnode_Level_Higher_Then_Get_Old_Value) {
    Neuron neuron1(10);
    Neuron neuron2(1);
    neuron2.addSubNodes(&neuron1, 0);
    neuron1.setValue(1);

    ASSERT_EQ(0, neuron2.getValue(INT32_MAX));
}

TEST(Neuron, testReset) {
    Neuron neuron1(10);
    Neuron neuron2(1);
    neuron2.addSubNodes(&neuron1, 0);
    neuron1.setValue(1); //old:0, new:1
    neuron1.reset(); //old:1, new:0

    ASSERT_EQ(1, neuron2.getValue(INT32_MAX));
}