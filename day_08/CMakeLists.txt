get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(APP_NAME "app_${DIR_NAME}")

project(${APP_NAME} VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wunused -pedantic)

add_executable(${APP_NAME} main.cpp)

target_link_libraries(${APP_NAME}
        PRIVATE
        fmt::fmt
        inputManager_lib
        tokenizer_lib
        outputBuilder_lib
        2Dutils_lib
)

add_subdirectory(ut)