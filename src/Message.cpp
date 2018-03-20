//
// Created by Oleksandra Baukh on 3/19/18.
//

#include "Message.h"

mark_os::communication::Message::Message(const char *content, uint8 size) {
}

mark_os::communication::Message::~Message() {
    delete[] content;
}
