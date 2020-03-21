#include <gtest/gtest.h>

#include "NeuralChamber.h"

TEST(NeuralChamber, testConstract_Without_Rintime_Error) {
    NeuralChamber chamber(10);

    ASSERT_EQ(0, 0);
}