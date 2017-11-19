cmake_minimum_required(VERSION 3.7)
project(sebesy)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++1z -Wall -Werror")

set(SOURCE_FILES main.cpp esy.cpp seb.cpp)
add_executable(sebesy ${SOURCE_FILES})