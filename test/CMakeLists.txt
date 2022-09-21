include(CTest)

# set test build target name
set(TEST_BINARY ${PROJECT_NAME}_test)
message("test_binary = ${TEST_BINARY}")

# add new test
add_executable(${TEST_BINARY} unit_test1.cpp)
#add_executable(${TEST_BINARY}_2 unit_test2.cpp)

# add googletest subdirectory
add_subdirectory(gtest-release-1.12.1)
# this is so we can #include <gtest/gtest.h>
include_directories(gtest-release-1.12.1/googletest/include)
include_directories(gtest-release-1.12.1/googlemock/include)

#message("current cmake = ${CMAKE_CURRENT_SOURCE_DIR}")

add_test(test1 ${TEST_BINARY})
### add_test(test2 ${TEST_BINARY}_2)

# link libraries to use in this executable
# link gtest_main to avoid your own main.cpp
target_link_libraries(${TEST_BINARY} PUBLIC gtest gtest_main)
### target_link_libraries(${TEST_BINARY}_2 PUBLIC gtest gtest_main)