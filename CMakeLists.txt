cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(bin/runTests test/main_test.cpp test/extraTest.cpp test/squareTest.cpp)
target_link_libraries(bin/runTests ${GTEST_LIBRARIES} pthread)
