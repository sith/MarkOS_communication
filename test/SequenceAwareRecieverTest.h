//
// Created by Oleksandra Baukh on 4/15/18.
//

#ifndef MARKOS_MAIN_SEQUENCEAWARERECIEVERTEST_H
#define MARKOS_MAIN_SEQUENCEAWARERECIEVERTEST_H


#include <gtest/gtest.h>
#include "../src/SequenceAwareReceiver.h"
#include "../../controller/test/MockReceiver.h"

class SequenceAwareRecieverTest : public testing::Test {
protected:
    mark_os::communication::MockReceiver<int> mockReceiver;
    mark_os::communication::SequenceAwareReceiver<int, 2> receiver{mockReceiver};
};


#endif //MARKOS_MAIN_SEQUENCEAWARERECIEVERTEST_H
