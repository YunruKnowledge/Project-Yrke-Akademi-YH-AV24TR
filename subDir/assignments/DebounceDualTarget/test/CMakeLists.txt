cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME assignment)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

project(${PROJECT_NAME} VERSION 1.0
                        DESCRIPTION "Assignment"
                        LANGUAGES C)

add_library(unity STATIC unity/unity.c)
target_include_directories(unity PRIVATE unity)

add_library(button STATIC ../lib/button/button.c)
target_include_directories(button PRIVATE test_button)
target_compile_options(button PRIVATE --coverage)

add_executable(test_button test_button/test.c test_button/bsp.c)
target_include_directories(test_button PRIVATE test_button ../lib/button)
target_link_libraries(test_button PRIVATE button unity)
target_compile_options(test_button PRIVATE -DNO_ESP)
target_link_options(test_button PRIVATE --coverage)

add_custom_target(coverage test_button COMMAND gcovr -r ${CMAKE_SOURCE_DIR}/.. --html-details -o ${CMAKE_BINARY_DIR}/index.html)
add_custom_target(esp cd ${CMAKE_SOURCE_DIR}/.. && pio run -t upload -t monitor)
add_custom_target(esp_test cd ${CMAKE_SOURCE_DIR}/.. && pio test)

enable_testing()
add_test(NAME test_button COMMAND test_button)