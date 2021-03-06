//
// Created by Oleksandra Baukh on 3/19/18.
//

#ifndef MARKOS_MAIN_TRANSMITTER_H
#define MARKOS_MAIN_TRANSMITTER_H

#include <types.h>
#include "Message.h"

namespace mark_os {
    namespace communication {
        template<typename Content>
        class Transceiver {
        public:
            virtual void send(Message<Content> &message)= 0;
        };
    }
}

#endif //MARKOS_MAIN_TRANSMITTER_H
