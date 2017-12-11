project(T-spin-Helper)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -w -std=c++11")
 
# Locate Libraries
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(bin/runTests EXCLUDE_FROM_ALL test/main_test.cpp) 
target_link_libraries(bin/runTests ${GTEST_LIBRARIES} pthread)

#Make game executable
add_executable(bin/${PROJECT_NAME} src/main.cpp src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Map.cpp)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(bin/${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
