//
// Created by Oleksandra Baukh on 3/19/18.
//

#ifndef MARKOS_MAIN_TRANSMITTER_H
#define MARKOS_MAIN_TRANSMITTER_H

#include "Message.h"

namespace mark_os {
    namespace communication {
        class Transceiver {
        public:
            virtual void send(uint8 channelId, Message &message)= 0;
        };
    }
}

#endif //MARKOS_MAIN_TRANSMITTER_H
