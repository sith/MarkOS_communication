#ifndef MARKOS_MAIN_TRANSCEIVERWITHRETRIESTEST_H
#define MARKOS_MAIN_TRANSCEIVERWITHRETRIESTEST_H


#include <gtest/gtest.h>
#include <TransceiverWithRetries.h>
#include <TransceiverWithRetries.cpp>
#include "../../controller/test/MockTransceiver.h"

class TransceiverWithRetriesTest : public testing::Test {

protected:
    mark_os::communication::MockTransceiver<int> transceiver;
    mark_os::communication::TransceiverWithRetries<int> transceiverWithRetries{transceiver, 2};

    void SetUp() override;
};


#endif //MARKOS_MAIN_TRANSCEIVERWITHRETRIESTEST_H
