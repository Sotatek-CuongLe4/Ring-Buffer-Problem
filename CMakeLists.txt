cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)
PROJECT(ringbuffer)

# Coverage flags PHẢI ĐẶT TRƯỚC add_library
option(CODE_COVERAGE "Enable coverage reporting" ON)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "Code coverage enabled")
    add_compile_options(--coverage -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
endif()

# Library
add_library(ringbuffer STATIC src/ringbuffer.cpp)
target_include_directories(ringbuffer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Executables
add_executable(main main.cpp)
target_link_libraries(main PRIVATE ringbuffer pthread)

add_executable(test_ringbuffer test/test_ringbuffer.cpp)
target_include_directories(test_ringbuffer PRIVATE include)
target_link_libraries(test_ringbuffer ringbuffer gtest gtest_main pthread)

# Testing
enable_testing()
add_test(NAME RingBufferTests COMMAND test_ringbuffer)