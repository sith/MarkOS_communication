//
// Created by Oleksandra Baukh on 4/8/18.
//

#include "TransceiverWithRetries.h"

namespace mark_os {
    namespace communication {
        template<typename Content>
        void TransceiverWithRetries<Content>::send(Message<Content> &message) {
            for (int i = 0; i < numberOfRetries; i++) {
                transceiver->send(message);
            }
        }

        template<typename Content>
        TransceiverWithRetries<Content>::TransceiverWithRetries(Transceiver<Content> &transceiver,
                                                                uint8 numberOfRetries) :transceiver(&transceiver),
                                                                                        numberOfRetries(
                                                                                                numberOfRetries) {

        }
    }
}