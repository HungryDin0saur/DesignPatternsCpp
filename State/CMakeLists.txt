cmake_minimum_required(VERSION 3.5)

project(State LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(State main.cpp)

install(TARGETS State
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
