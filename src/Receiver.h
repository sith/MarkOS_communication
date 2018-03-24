//
// Created by Oleksandra Baukh on 3/19/18.
//

#ifndef MARKOS_MAIN_RECIVIER_H
#define MARKOS_MAIN_RECIVIER_H


#include <types.h>
#include "Message.h"

namespace mark_os {
    namespace communication {
        template<typename Content>
        class Receiver {
        public:
            virtual Message<Content> receive()= 0;

            virtual bool available()= 0;
        };
    }
}
#endif //MARKOS_MAIN_RECIVIER_H
