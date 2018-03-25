//
// Created by Oleksandra Baukh on 3/22/18.
//

#ifndef MARKOS_MAIN_MESSAGE_H
#define MARKOS_MAIN_MESSAGE_H

#include <types.h>

template<typename Content>
struct Message {
    uint16 signature = version;
    uint8 from = 0;
    uint8 to = 0;
    Content content;

    static const uint16 version = 12496;

    Message() = default;

    Message(Content content) : content(content) {}

    Message(uint8 from, uint8 to, Content content) : from(from), to(to), content(content) {}

    bool operator==(const Message &rhs) const {
        return from == rhs.from &&
               to == rhs.to &&
               content == rhs.content;
    }

    bool operator!=(const Message &rhs) const {
        return !(rhs == *this);
    }

};

#endif //MARKOS_MAIN_MESSAGE_H
