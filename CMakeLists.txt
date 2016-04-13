# run through qt creator add -DCMAKE_BUILD_TYPE=Debug as a flag before httting the run cmake button.
cmake_minimum_required (VERSION 2.6)

project(AtoR)

set (SOURCE  source/main.cpp
     source/arabic_toroman.hpp
     source/arabic_toroman.cpp)

add_executable(AtoR ${SOURCE})
target_compile_options(AtoR PUBLIC -std=c++14)
