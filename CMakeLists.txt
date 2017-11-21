cmake_minimum_required(VERSION 3.7)
project(sebesy)

set(CMAKE_CXX_FLAGS "-std=c++1z -Wall -Werror -Wextra -fsanitize=address")

set(SOURCE_FILES main.cpp esy.cpp seb.cpp utilities.cpp)
add_executable(sebesy ${SOURCE_FILES})