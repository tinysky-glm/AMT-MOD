project(amt-mod)

cmake_minimum_required(VERSION 3.9)

option(test "Build all tests" ON)
enable_testing()
set(CMAKE_VERBOSE_MAKEFILE ON)

if(APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_USE_OWN_TR1_TUPLE=1")
endif(APPLE)

include(${PROJECT_SOURCE_DIR}/cmake/Utils.cmake)

include_directories(
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/thirdparty/
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -ftree-vectorize -Wcpp -O2 -g")

add_subdirectory(mod)
add_subdirectory(thirdparty)
add_subdirectory(tools)
add_subdirectory(test)
add_subdirectory(benchmark)
