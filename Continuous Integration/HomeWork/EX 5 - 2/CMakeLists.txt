cmake_minimum_required(VERSION 3.22)

project(test)

add_executable(test test/test.cpp lib/queue.h)

target_link_libraries(test PRIVATE  gtest gtest_main)
target_include_directories(test PRIVATE test/ lib/)