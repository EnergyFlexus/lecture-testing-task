cmake_minimum_required(VERSION 3.10)
project(stack)

add_library(stack src/stack.c)
add_library(stack::library ALIAS stack)

add_executable(main src/main.c)
target_link_libraries(main stack)

# sanitizer setup if debug
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_options(main PRIVATE -fsanitize=address -fno-omit-frame-pointer)
	target_link_options(main PRIVATE -fsanitize=address)
endif()

# tests setup
add_subdirectory(test)
enable_testing()
add_test(tests test/tests)

# benchmark setup
add_subdirectory(benchmark)