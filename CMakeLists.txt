cmake_minimum_required(VERSION 3.10)
project(MarkOS_communication)

add_library(${PROJECT_NAME} src/Transceiver.h src/Receiver.h src/Message.cpp src/Message.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)

target_link_libraries(${PROJECT_NAME} MarkOS_commons)

