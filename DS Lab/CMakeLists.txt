cmake_minimum_required(VERSION 3.31)
project(DS)

set(CMAKE_CXX_STANDARD 20)

add_executable(target_1 linearsearch.cpp)
add_executable(target_2 binarysearch.cpp)
add_executable(target_3 rbinarysearch.cpp)

