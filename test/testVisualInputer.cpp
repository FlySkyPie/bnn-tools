#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::_;
using ::testing::Return;

#include "VisualInputer.h"
#include "NeuralInputInterface.h"

class MockNeuralInput : public NeuralInputInterface {
public:
    MOCK_METHOD1(getInputNodeIds, std::unordered_set<uint32_t> (uint32_t));
    MOCK_METHOD0(reset, void());
    MOCK_METHOD2(setValue, void(uint32_t, bool));
};

TEST(VisualInputer, testConstract_Without_Rintime_Error) {
    MockNeuralInput mock;
    EXPECT_CALL(mock, getInputNodeIds(_)).Times(1);

    VisualInputer inputer(800, 600, &mock);
}


TEST(VisualInputer, testUpdateImage_With_Three_Nodes) {
    MockNeuralInput mock;
    std::unordered_set<uint32_t> set({1, 2, 3});
    EXPECT_CALL(mock, getInputNodeIds(_)).Times(1)
            .WillRepeatedly(Return(set));

    EXPECT_CALL(mock, setValue(_, _)).Times(3);
    EXPECT_CALL(mock, reset()).Times(1);

    VisualInputer inputer(8, 6, &mock);
    cv::Mat mat(8, 6, CV_8UC3);
    inputer.updateImage(&mat);
}/**/