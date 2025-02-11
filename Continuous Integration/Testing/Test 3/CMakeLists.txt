cmake_minimum_required(VERSION 3.22)

project(DateTemplate)

include_directories(includes)
#include_directories(lib/date)
include_directories(lib/today)

add_executable(test test/test.cpp)

target_link_libraries(test PRIVATE gtest gtest_main)
link_directories(test PRIVATE test/ lib/date/ lib/today/ includes/)
