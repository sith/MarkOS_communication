//
// Created by Oleksandra Baukh on 4/8/18.
//

#include <gmock/gmock.h>
#include "SequenceAwareTransceiverTest.h"

using ::testing::Exactly;

void SequenceAwareTransceiverTest::SetUp() {
    Test::SetUp();
}

TEST_F(SequenceAwareTransceiverTest, incrementSequence) {

    Message<int> message1;
    message1.content = 123;

    Message<int> message2;
    message1.content = 123;

    Message<int> expectedMessage1 = message1;
    expectedMessage1.sequence = 1;

    Message<int> expectedMessage2 = message2;
    expectedMessage2.sequence = 2;

    EXPECT_CALL(mockTransceiver, send(expectedMessage1));
    EXPECT_CALL(mockTransceiver, send(expectedMessage2));

    transceiver.send(message1);
    transceiver.send(message2);
}
