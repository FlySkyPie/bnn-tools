#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::_;
using ::testing::Return;

#include "BreakoutActionMaker.h"
#include "NeuralOutputInterface.h"

class MockNeuralOutput : public NeuralOutputInterface {
public:
    MOCK_METHOD1(getValue, bool (uint32_t));
};

TEST(BreakoutActionMaker, testConstruct_Without_Rintime_Error) {
    MockNeuralOutput mock;

    BreakoutActionMaker action(&mock);
}

TEST(BreakoutActionMaker, testgetAction_With_Right_Should_Get_Two) {
    MockNeuralOutput mock;
    EXPECT_CALL(mock, getValue(0)).Times(1).WillRepeatedly(Return(true));
    EXPECT_CALL(mock, getValue(1)).Times(1).WillRepeatedly(Return(false));

    BreakoutActionMaker action(&mock);
    ASSERT_EQ(2, action.getAction());
}

TEST(BreakoutActionMaker, testgetAction_With_Left_Should_Get_Three) {
    MockNeuralOutput mock;
    EXPECT_CALL(mock, getValue(0)).Times(1).WillRepeatedly(Return(true));
    EXPECT_CALL(mock, getValue(1)).Times(1).WillRepeatedly(Return(true));

    BreakoutActionMaker action(&mock);
    ASSERT_EQ(3, action.getAction());
}

TEST(BreakoutActionMaker, testgetAction_With_Fire_Should_Get_One) {
    MockNeuralOutput mock;
    EXPECT_CALL(mock, getValue(0)).Times(1).WillRepeatedly(Return(false));
    EXPECT_CALL(mock, getValue(1)).Times(1).WillRepeatedly(Return(true));

    BreakoutActionMaker action(&mock);
    ASSERT_EQ(1, action.getAction());
}

TEST(BreakoutActionMaker, testgetAction_With_Idle_Should_Get_Zero) {
    MockNeuralOutput mock;
    EXPECT_CALL(mock, getValue(0)).Times(1).WillRepeatedly(Return(false));
    EXPECT_CALL(mock, getValue(1)).Times(1).WillRepeatedly(Return(false));

    BreakoutActionMaker action(&mock);
    ASSERT_EQ(0, action.getAction());
}