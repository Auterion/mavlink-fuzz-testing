cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 14)

project(mavlink_fuzz_testing)

set(CMAKE_CXX_FLAGS -fsanitize=fuzzer,address,undefined)

include_directories(../generated/include/mavlink/v2.0)

add_executable(parser_brute_force
    parser_brute_force.cpp
)

add_executable(parser_with_random_message
    parser_with_random_message.cpp
)

add_executable(parser_with_assembled_message
    parser_with_assembled_message.cpp
)
