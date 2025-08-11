cmake_minimum_required(VERSION 3.10)

project(ds LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-fmodules-ts)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main
    utils.cpp
    vector.cpp
    main.cpp
)