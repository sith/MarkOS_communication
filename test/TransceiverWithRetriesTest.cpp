//
// Created by Oleksandra Baukh on 4/8/18.
//

#include "TransceiverWithRetriesTest.h"

using ::testing::Exactly;

void TransceiverWithRetriesTest::SetUp() {
    Test::SetUp();
}

TEST_F(TransceiverWithRetriesTest, mainTest) {
    Message<int> message;
    message.content = 7;
    EXPECT_CALL(transceiver, send(message)).Times(Exactly(2));

    transceiverWithRetries.send(message);
}
