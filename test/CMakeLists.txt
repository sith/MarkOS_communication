
add_executable(communication_tests
        main.cpp
        TransceiverWithRetriesTest.cpp TransceiverWithRetriesTest.h SequenceAwareTransceiverTest.cpp SequenceAwareTransceiverTest.h SequenceAwareRecieverTest.cpp SequenceAwareRecieverTest.h)

#Link with GoogleTest
target_link_libraries(communication_tests gtest gtest_main)
#Link with GoogleMock
target_link_libraries(communication_tests gmock gmock_main)
target_link_libraries(communication_tests MarkOS_communication)
target_link_libraries(communication_tests MarkOS_controller_test)