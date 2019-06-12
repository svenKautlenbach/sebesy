cmake_minimum_required(VERSION 3.11)

project(sebesy LANGUAGES CXX)

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_SYSTEM_NAME)
cmake_print_variables(CMAKE_CXX_COMPILER_ID)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU
        OR CMAKE_CXX_COMPILER_ID MATCHES Clang
        OR CMAKE_CXX_COMPILER_ID MATCHES AppleClang)
    set(_compile_options -Wall -Werror -Wextra -g)
elseif(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    set(_compile_options W4)
else()
    message(FATAL_ERROR " Unsupported compiler: " ${CMAKE_CXX_COMPILER_ID})
endif()


include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)

add_executable(sebesy ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)
set_target_properties(sebesy
        PROPERTIES
            CXX_STANDARD 14
            CXX_EXTENSIONS OFF
            CXX_STANDARD_REQUIRED ON
            POSITION_INDEPENDENT_CODE 1
        )
target_include_directories(sebesy PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src/include)
target_compile_options(sebesy PRIVATE ${_compile_options})
target_link_libraries(sebesy sebesy-static)

target_compile_options(sebesy-objs PRIVATE ${_compile_options})

include(${CMAKE_CURRENT_LIST_DIR}/test/CMakeLists.txt)
