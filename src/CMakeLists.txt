cmake_minimum_required(VERSION 3.7)

list(APPEND _sources
        ${CMAKE_CURRENT_LIST_DIR}/esy.cpp
        ${CMAKE_CURRENT_LIST_DIR}/seb.cpp
        ${CMAKE_CURRENT_LIST_DIR}/utilities.cpp)

add_library(sebesy-objs
        OBJECT
            ${_sources}
        )
set_target_properties(sebesy-objs
        PROPERTIES
        CXX_STANDARD 14
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE 1
        )
target_include_directories(sebesy-objs PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_library(sebesy-static
        STATIC
            $<TARGET_OBJECTS:sebesy-objs>
        )
set_target_properties(sebesy-static
        PROPERTIES
            OUTPUT_NAME sebesy
        )
