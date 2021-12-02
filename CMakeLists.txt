cmake_minimum_required(VERSION 3.0.0)

project(ADVENT_OF_CODE)

# add -O0 to remove optimizations from debug builds just to be sure
IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

add_executable(day01Sonar day01/sonarSweep.cpp)
add_executable(day02SubmarineMotion day02/submarineMotion.cpp)
