
add_library(inputManager_lib
        InputManager.cpp
)

target_include_directories(inputManager_lib
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)