//
// Created by Oleksandra Baukh on 4/15/18.
//

#include "SequenceAwareRecieverTest.h"

using namespace testing;

TEST_F(SequenceAwareRecieverTest, recieveMessagesWithTheSameSequence) {
    Message<int> someMessage;
    someMessage.sequence = 1;
    someMessage.content = 1234;

    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(2)).WillRepeatedly(
            Return(mark_os::commons::optional(someMessage)));

    auto firstMessage = receiver.receive();
    ASSERT_TRUE(firstMessage);
    ASSERT_EQ(firstMessage.get(), someMessage);

    auto secondMessage = receiver.receive();
    ASSERT_FALSE(secondMessage);
}


TEST_F(SequenceAwareRecieverTest, allowOldMessagesAfterOldSequenceNumberWasEvictedFromTheMemory) {

    Message<int> message1;
    message1.sequence = 1;
    message1.content = 1;

    Message<int> message2;
    message2.sequence = 2;
    message2.content = 2;

    Message<int> message3;
    message3.sequence = 3;
    message3.content = 3;

    EXPECT_CALL(mockReceiver, receive()).Times(Exactly(5))
            .WillOnce(Return(mark_os::commons::optional(message1)))
            .WillOnce(Return(mark_os::commons::optional(message1)))
            .WillOnce(Return(mark_os::commons::optional(message2)))
            .WillOnce(Return(mark_os::commons::optional(message3)))
            .WillOnce(Return(mark_os::commons::optional(message1)));

    auto receivedMessage1 = receiver.receive();
    ASSERT_TRUE(receivedMessage1);
    ASSERT_EQ(receivedMessage1.get(), message1);

    auto receivedMessage1FirstTime = receiver.receive();
    ASSERT_FALSE(receivedMessage1FirstTime);

    auto receivedMessage2 = receiver.receive();
    ASSERT_TRUE(receivedMessage2);
    ASSERT_EQ(receivedMessage2.get(), message2);

    auto receivedMessage3 = receiver.receive();
    ASSERT_TRUE(receivedMessage3);
    ASSERT_EQ(receivedMessage3.get(), message3);

    auto receivedMessage1SecondTime = receiver.receive();
    ASSERT_TRUE(receivedMessage1SecondTime);
    ASSERT_EQ(receivedMessage1SecondTime.get(), message1);
}
