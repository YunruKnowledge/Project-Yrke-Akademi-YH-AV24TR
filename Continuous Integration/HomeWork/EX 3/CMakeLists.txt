cmake_minimum_required(VERSION "3.22")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_EXTENSIONS OFF)

# Compiler flags
add_compile_options(-Wall -Wextra -Wpedantic)

# Project definition
project("test_app")

# Add executable for testing
add_executable("test_app" "test/test.cpp")

# Add greetings library
add_library("greetings" "lib/greetings.cpp")

# Link the greetings and GoogleTest libraries to the test executable
target_link_libraries("test_app" PRIVATE greetings)

# Include directories
target_include_directories("test_app" PRIVATE "lib/" "test/")

# Download and include GoogleTest if not found
if (NOT TARGET gtest)
    include(FetchContent)
    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1  # Use the latest stable release or any version you prefer
    )
    FetchContent_MakeAvailable(gtest)
endif()

# Link GoogleTest to the test executable
target_link_libraries("test_app" PRIVATE gtest)

# Enable testing and add a test for CTest
enable_testing()
add_test(NAME "test" COMMAND test_app)
