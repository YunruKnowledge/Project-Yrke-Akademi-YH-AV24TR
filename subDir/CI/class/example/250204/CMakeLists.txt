cmake_minimum_required(VERSION 3.22.1)

project(test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)

FetchContent_MakeAvailable(googletest)

add_executable(test main.cpp)
target_link_libraries(test PRIVATE googletest)
