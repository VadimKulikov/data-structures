cmake_minimum_required(VERSION 3.10)
include(FetchContent)

project(ds LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-fmodules-ts)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG        v1.11.0
)
FetchContent_MakeAvailable(spdlog)

add_executable(main
    vector.cpp
    vector.hpp
    main.cpp
)
target_link_libraries(main PRIVATE spdlog::spdlog)