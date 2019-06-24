cmake_minimum_required(VERSION 3.11)

project(sebesy-unit-tests LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.8.0
)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)

    # Prevent GoogleTest from overriding our compiler/linker options
    # when building with Visual Studio
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    # Prevent GoogleTest from using PThreads
    set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)

    # adds the targers: gtest, gtest_main, gmock, gmock_main
    add_subdirectory(
            ${googletest_SOURCE_DIR}
            ${googletest_BINARY_DIR}
    )

    # Silence std::tr1 warning on MSVC
    if(MSVC)
        foreach(_tgt gtest gtest_main gmock gmock_main)
            target_compile_definitions(${_tgt}
                    PRIVATE
                    "_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING"
                    )
        endforeach()
    endif()
endif()

add_executable(sebesy-tests "")
target_sources(sebesy-tests
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/iban_test.cpp
            ${CMAKE_CURRENT_LIST_DIR}/bank_source_test.cpp
        )
set_target_properties(sebesy-tests
        PROPERTIES
            CMAKE_CXX_STANDARD 14
            CMAKE_CXX_EXTENSIONS OFF
            CMAKE_CXX_STANDARD_REQUIRED ON
            CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON
        )
target_link_libraries(sebesy-tests
        PRIVATE
            gmock
            gtest_main
            sebesy-objs
        )
target_include_directories(sebesy-tests PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../src/include)

enable_testing()

add_test(
        NAME sebesy_unit_test
        COMMAND $<TARGET_FILE:sebesy-tests>
)