cmake_minimum_required(VERSION 3.6)

project(weather)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -ggdb")
configure_file(CMakeLists.txt.in
    googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
    ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(test)
#
#
#

include_directories("${PROJECT_SOURCE_DIR}/include")
file(GLOB sources
    "${PROJECT_SOURCE_DIR}/include/weather/*.h"
    "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(run ${sources})
