project(amt-mod)

cmake_minimum_required(VERSION 3.9)

include(${PROJECT_SOURCE_DIR}/cmake/Utils.cmake)

if(APPLE)
mod_option(USE_QT "USE_QT GUI" ON)
endif(APPLE)

option(test "Build all tests" ON)
enable_testing()
set(CMAKE_VERBOSE_MAKEFILE ON)

if(APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_USE_OWN_TR1_TUPLE=1")
endif(APPLE)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

if (USE_QT)
# manually set the QT's path based on system's envronment
set(QT_PATH ENV{QT_PATH})
# Find the QtWidgets library
set(QT5Core_DIR "${QT_PATH}/lib/cmake/Qt5Core")
find_package(Qt5Core)
set(QT5Core_DIR "${QT_PATH}/lib/cmake/Qt5Widgets")
find_package(Qt5Widgets)
set(QT5WebEngineWidgets_DIR "${QT_PATH}/lib/cmake/Qt5WebEngineWidgets")
find_package(QT5WebEngineWidgets)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/
    ${PROJECT_SOURCE_DIR}/thirdparty/
    ${Qt5Widgets_INCLUDE_DIRS}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fPIC -ftree-vectorize -Wcpp -O2 -g")

add_subdirectory(mod)
add_subdirectory(thirdparty)
add_subdirectory(tools)
add_subdirectory(test)
add_subdirectory(benchmark)
