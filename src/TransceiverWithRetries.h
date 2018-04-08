//
// Created by Oleksandra Baukh on 4/8/18.
//

#ifndef MARKOS_MAIN_TRANSCEIVERWITHRETRIES_H
#define MARKOS_MAIN_TRANSCEIVERWITHRETRIES_H

#include "Transceiver.h"

namespace mark_os {
    namespace communication {
        template<typename Content>
        class TransceiverWithRetries : public Transceiver<Content> {
            Transceiver<Content> *transceiver;
            uint8 numberOfRetries;
        public:

            TransceiverWithRetries(Transceiver<Content> &transceiver, uint8 numberOfRetries);

            void send(Message<Content> &message) override;
        };

    }
}

#endif //MARKOS_MAIN_TRANSCEIVERWITHRETRIES_H
