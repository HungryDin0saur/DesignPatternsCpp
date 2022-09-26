cmake_minimum_required(VERSION 3.5)

project(Decorator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Decorator main.cpp)

install(TARGETS Decorator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
