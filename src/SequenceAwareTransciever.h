//
// Created by Oleksandra Baukh on 4/8/18.
//

#ifndef MARKOS_MAIN_SEQUENCEAWARETRANSCIEVER_H
#define MARKOS_MAIN_SEQUENCEAWARETRANSCIEVER_H

#include "Transceiver.h"

namespace mark_os {
    namespace communication {
        template<typename Content>
        class SequenceAwareTransciever : public Transceiver<Content> {
            Transceiver<Content> *transceiver;
            uint16 sequenceNumber = 0;
        public:
            SequenceAwareTransciever(Transceiver<Content> &transceiver);

            void send(Message<Content> &message) override;
        };
    }
}
#endif //MARKOS_MAIN_SEQUENCEAWARETRANSCIEVER_H
