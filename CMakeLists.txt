cmake_minimum_required(VERSION 3.10)
project(MarkOS_communication)

add_library(${PROJECT_NAME}
        src/Transceiver.h
        src/Transceiver.cpp
        src/TransceiverWithRetries.h
        src/TransceiverWithRetries.cpp
        src/Receiver.h
        src/Receiver.cpp
        src/Message.h src/SequenceAwareTransciever.cpp src/SequenceAwareTransciever.h src/SequenceAwareReceiver.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} MarkOS_commons)
add_subdirectory(test)

install(DIRECTORY "src/"
        DESTINATION "/Users/oleksandrabaukh/workspace/libs/MarkOS/communication")
