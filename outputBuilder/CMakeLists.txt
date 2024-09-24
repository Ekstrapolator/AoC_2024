
add_library(outputBuilder_lib
    OutputBuilder.cpp
)

target_include_directories(outputBuilder_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)