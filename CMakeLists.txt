cmake_minimum_required(VERSION 3.20.0)
project(AoC2024 VERSION 0.1.0 LANGUAGES CXX)
include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 11.0.1
)
FetchContent_MakeAvailable(fmt)

add_subdirectory(inputManager)
add_subdirectory(tokenizer)

add_subdirectory(day_01)
