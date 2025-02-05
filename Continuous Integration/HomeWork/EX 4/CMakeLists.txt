cmake_minimum_required(VERSION "3.22")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

project("test_app")

add_executable("test_app" "test/test.cpp")

add_library("list" "lib/list.cpp")

target_link_libraries("test_app" PRIVATE list)

target_include_directories("test_app" PRIVATE "lib/" "test/")

target_link_libraries("test_app" PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME "test" COMMAND test_app)
