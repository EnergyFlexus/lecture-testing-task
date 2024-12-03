cmake_minimum_required(VERSION 3.10)
project(benchmark)

add_executable(benchmark benchmark.cpp)
target_link_libraries(benchmark PRIVATE stack::library)