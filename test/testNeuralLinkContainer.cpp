#include <gtest/gtest.h>
#include <gmock/gmock.h>
using::testing::_;

#include "NeuralLinkContainer.h"
#include "NeuralConstructInterface.h"

class MockNeuralConstruct : public NeuralConstructInterface {
public:
    MOCK_METHOD1(addNode, void(uint32_t));
    MOCK_METHOD3(addLink, void(uint32_t, uint32_t, bool));
};

TEST(NeuralLinkContainer, testConstruct_Two_Nodes_When_Two_Given) {
    NeuralLinkContainer container;
    MockNeuralConstruct mock;
    
    EXPECT_CALL(mock, addNode(_)).Times(2);
    EXPECT_CALL(mock, addLink(_, _, _)).Times(1);

    container.addLink(1, 10, true);
    container.construct(&mock);
}

TEST(NeuralLinkContainer, testConstruct_Ignore_Repeated_Link) {
    NeuralLinkContainer container;
    MockNeuralConstruct mock;
    
    EXPECT_CALL(mock, addNode(_)).Times(2);
    EXPECT_CALL(mock, addLink(_, _, _)).Times(1);

    container.addLink(1, 10, true);
    container.addLink(1, 10, true);
    container.construct(&mock);
}