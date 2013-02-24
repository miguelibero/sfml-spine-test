cmake_minimum_required(VERSION 2.8) 

set( CMAKE_CXX_FLAGS "-Wall -std=c++11 -Wno-unknown-pragmas" )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

project(sfml-spine-test)

set(LIB_DIR "${CMAKE_SOURCE_DIR}/../lib")
set(SRC_DIR "${CMAKE_SOURCE_DIR}/../src")
set(PLATFORM_SRC_DIR "${CMAKE_SOURCE_DIR}/src")

set(EXECUTABLE_NAME "sfml_spine_test")

file(GLOB_RECURSE MAIN_SOURCES
    "${SRC_DIR}/*.cpp"
)
file(GLOB_RECURSE MAIN_PLATFORM_SOURCES
    "${PLATFORM_SRC_DIR}/*.cpp"
)
add_executable (${EXECUTABLE_NAME} ${MAIN_SOURCES} ${MAIN_PLATFORM_SOURCES})

include_directories(${SRC_DIR} ${PLATFORM_SRC_DIR})

#sfml
set(CMAKE_MODULE_PATH "${LIB_DIR}/sfml/cmake/Modules" ${CMAKE_MODULE_PATH})
set($ENV{SFML_ROOT}, "${LIB_DIR}/sfml")
find_package(SFML 2 REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

#jsoncpp
set(JSONCPP_SRC_DIR "${LIB_DIR}/jsoncpp/src")
include_directories("${JSONCPP_SRC_DIR}")

#spine
set(SPINE_SRC_DIR "${LIB_DIR}/spine/spine-cpp/src")
set(SPINE_INCLUDE_DIR "${LIB_DIR}/spine/spine-cpp/includes")
include_directories("${SPINE_INCLUDE_DIR}")
file(GLOB SPINE_SOURCES
    "${SPINE_SRC_DIR}/json/*.cpp"
    "${SPINE_SRC_DIR}/spine/*.cpp"
    "${SPINE_SRC_DIR}/spine-sfml/*.cpp"
) 
add_library(spine ${SPINE_SOURCES})
target_link_libraries(${EXECUTABLE_NAME} spine)

