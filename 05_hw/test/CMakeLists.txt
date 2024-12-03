cmake_minimum_required(VERSION 3.12)
project(tests)

add_subdirectory(googletest)
include_directories(googletest/include)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(tests 
	tests/test_stack.cpp
	tests/test_smoke.cpp
	../src/stack.c)

target_compile_options(tests PRIVATE -coverage -fprofile-instr-generate -fcoverage-mapping)
target_link_options(tests PRIVATE -coverage)

target_link_libraries(tests PRIVATE gtest gtest_main)

# clear gcda files
execute_process(COMMAND rm -f *.gcda WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/tests.dir/tests)