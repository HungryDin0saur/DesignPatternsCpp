cmake_minimum_required(VERSION 3.5)

project(Prototype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Prototype main.cpp)

install(TARGETS Prototype
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
