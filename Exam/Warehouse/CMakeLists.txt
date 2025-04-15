cmake_minimum_required(VERSION 3.30)
project(main)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp
        lib/vehicle.h
        lib/warehouse.h)

target_include_directories(main PRIVATE lib/)