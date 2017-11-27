cmake_minimum_required(VERSION 3.0)
project(messaged)

# src files
set(SRC_SERVER
        src/Message.cpp
        src/messaged.cpp
        src/User.cpp
        src/Session.cpp
        src/Socket.cpp)

set(SRC_THREAD_TEST
        src/threadTest.cpp)

# settings
set (CMAKE_CXX_STANDARD 11)
link_libraries(pthread)

# executables
add_executable(server ${SRC_SERVER})
add_executable(threadTest ${SRC_THREAD_TEST})