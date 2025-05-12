cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME assignment)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

project(${PROJECT_NAME} VERSION 1.0
                        DESCRIPTION "Assignment"
                        LANGUAGES C)