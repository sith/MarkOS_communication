
#ifndef MARKOS_MAIN_SEQUENCEAWARERECIEVER_H
#define MARKOS_MAIN_SEQUENCEAWARERECIEVER_H

#include "Receiver.h"

namespace mark_os {
    namespace communication {
        template<typename Content, uint8 MemorySize = 10>
        class SequenceAwareReceiver : public Receiver<Content> {
            Receiver<Content> *receiver;
            uint16 receivedMessages[MemorySize]{0};
            uint16 lastIndex = 0;

        public:
            explicit SequenceAwareReceiver(Receiver<Content> &receiver) : receiver(&receiver) {}

            commons::Optional<Message<Content>> receive() override {

                auto message = receiver->receive();
                if (message) {

                    auto sequence = message().sequence;

                    for (auto &&receivedMessage : receivedMessages) {
                        if (sequence == receivedMessage) {
                            return commons::none<Message<Content>>();
                        }
                    }

                    receivedMessages[lastIndex] = sequence;

                    lastIndex = ++lastIndex % MemorySize;

                    return message;
                }
                return commons::none<Message<Content>>();
            }
        };
    }
}

#endif //MARKOS_MAIN_SEQUENCEAWARERECIEVER_H
