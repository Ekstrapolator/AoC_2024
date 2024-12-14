add_library(2Dutils_lib INTERFACE
)

target_include_directories(2Dutils_lib
        INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
)

message(STATUS "2Dutils include directories: ${CMAKE_CURRENT_LIST_DIR}")