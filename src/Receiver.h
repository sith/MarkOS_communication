//
// Created by Oleksandra Baukh on 3/19/18.
//

#ifndef MARKOS_MAIN_RECIVIER_H
#define MARKOS_MAIN_RECIVIER_H

#include "Message.h"

namespace mark_os {
    namespace communication {
        class Receiver {
            virtual Message receive(uint8 channelId)= 0;
        };
    }
}
#endif //MARKOS_MAIN_RECIVIER_H
