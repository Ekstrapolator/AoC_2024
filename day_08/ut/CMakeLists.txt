
add_executable(TEST_xxx
        Test.cpp
)
target_link_libraries(TEST_xxx
        PRIVATE
        gtest_main
        inputManager_lib
        2Dutils_lib
        fmt::fmt

)

include(GoogleTest)
gtest_discover_tests(TEST_xxx)