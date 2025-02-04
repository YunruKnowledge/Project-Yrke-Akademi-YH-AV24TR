
cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

project(exec3)

add_library(greet lib/greet/greet.cpp)
target_include_directories(greet PUBLIC lib/greet/)

add_executable(run_test test/test.cpp)
target_link_libraries(run_test PRIVATE greet gtest gtest_main)
target_include_directories(run_test PRIVATE lib/greet test)

enable_testing()
add_test(NAME run_test COMMAND run_test)