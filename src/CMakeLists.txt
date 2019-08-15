cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")

project(mavlink_fuzz_testing)

set(CMAKE_CXX_FLAGS -fsanitize=fuzzer)

include_directories(../generated/include/mavlink/v2.0)

add_executable(parser_fuzzing
    target.cpp
)

