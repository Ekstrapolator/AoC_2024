
add_library(tokenizer_lib
    Tokenizer.cpp
)

target_include_directories(tokenizer_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(tokenizer_lib
        PRIVATE
        fmt::fmt
)