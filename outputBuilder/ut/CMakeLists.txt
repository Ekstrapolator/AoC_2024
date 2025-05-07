
add_executable(TEST_HelperDay6
        TestHelperDay6.cpp
)
target_link_libraries(TEST_HelperDay6
        PRIVATE
        gtest_main
        inputManager_lib
        2Dutils_lib
        fmt::fmt
        helperDay6
)

include(GoogleTest)
gtest_discover_tests(TEST_HelperDay6)