cmake_minimum_required(VERSION 3.13)
project(course)

set(CMAKE_CXX_STANDARD 14)

add_executable(operator rational_operators.cpp)
add_executable(str_double_index string_operator_index.cpp)
add_executable(smart arithmetics.h smart_pointer.cpp)
add_executable(template template_array.cpp)