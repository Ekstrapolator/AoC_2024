cmake_minimum_required(VERSION 3.20.0)
project(AoC2024 VERSION 0.1.0 LANGUAGES CXX)
include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 11.0.1
)
FetchContent_MakeAvailable(fmt)


include(CTest)
enable_testing()

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(inputManager)
add_subdirectory(tokenizer)
add_subdirectory(2Dutils)
add_subdirectory(outputBuilder)


add_subdirectory(day_01)
add_subdirectory(day_02)
add_subdirectory(day_03)
add_subdirectory(day_04)
add_subdirectory(day_05)
add_subdirectory(day_06)