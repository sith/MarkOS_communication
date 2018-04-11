//
// Created by Oleksandra Baukh on 4/8/18.
//

#include "SequenceAwareTransciever.h"

namespace mark_os {
    namespace communication {

        template<typename Content>
        void SequenceAwareTransciever<Content>::send(Message<Content> &message) {
            message.sequence = ++sequenceNumber;
            transceiver->send(message);
        }

        template<typename Content>
        SequenceAwareTransciever<Content>::SequenceAwareTransciever(Transceiver<Content> &transceiver) : transceiver{
                &transceiver} {
        }
    }
}