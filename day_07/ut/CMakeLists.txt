
add_executable(TEST_${DIR_NAME}
        Test_${DIR_NAME}.cpp
)
target_link_libraries(TEST_${DIR_NAME}
        PRIVATE
        gtest_main
        inputManager_lib
        2Dutils_lib
        fmt::fmt
        tokenizer_lib
)

include(GoogleTest)
gtest_discover_tests(TEST_${DIR_NAME})