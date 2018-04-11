//
// Created by Oleksandra Baukh on 4/8/18.
//

#ifndef MARKOS_MAIN_SEQUENCEAWARETRANSCIEVERTEST_H
#define MARKOS_MAIN_SEQUENCEAWARETRANSCIEVERTEST_H


#include <gtest/gtest.h>
#include <SequenceAwareTransciever.h>
#include <SequenceAwareTransciever.cpp>
#include "../../controller/test/MockTransceiver.h"

class SequenceAwareTransceiverTest : public ::testing::Test {
protected:
    void SetUp() override;

    mark_os::communication::MockTransceiver<int> mockTransceiver;
    mark_os::communication::SequenceAwareTransciever<int> transceiver{mockTransceiver};

};


#endif //MARKOS_MAIN_SEQUENCEAWARETRANSCIEVERTEST_H
