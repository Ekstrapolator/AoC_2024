if(BUILD_TESTING)
    add_subdirectory(ut)
endif ()

add_library(helperDay6
    HelperDay6.cpp
)

target_include_directories(helperDay6
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(helperDay6
        PRIVATE
        fmt::fmt
        tokenizer_lib
        inputManager_lib
        2Dutils_lib
)

add_library(outputBuilder_lib
    OutputBuilder.cpp
)

target_include_directories(outputBuilder_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(outputBuilder_lib
        PRIVATE
        fmt::fmt
        tokenizer_lib
        inputManager_lib
        2Dutils_lib
        helperDay6
)

get_target_property(include_dirs outputBuilder_lib INCLUDE_DIRECTORIES)
message(STATUS "Include directories for main: ${include_dirs}")