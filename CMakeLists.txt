cmake_minimum_required(VERSION 3.10)

project(Vector C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(vector STATIC vector.c vector.h)

add_executable(vector_main main.c)
target_link_libraries(vector_main vector)