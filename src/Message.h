//
// Created by Oleksandra Baukh on 3/19/18.
//

#ifndef MARKOS_MAIN_MESSAGE_H
#define MARKOS_MAIN_MESSAGE_H

#include <types.h>

namespace mark_os {
    namespace communication {
        class Message {
            const char *content;
            uint8 size;
        public:
            Message(const char *content, uint8 size);
            virtual ~Message();
        };
    }
}

#endif //MARKOS_MAIN_MESSAGE_H
