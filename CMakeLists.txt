cmake_minimum_required(VERSION 3.31)
project(DS)

set(CMAKE_CXX_STANDARD 20)

add_executable(target_1 linearsearch.cpp)
add_executable(target_2 binarysearch.cpp)
add_executable(target_3 rbinarysearch.cpp)
add_executable(target_4 bubblesort.cpp)
add_executable(target_5 selectionsort.cpp)
add_executable(target_6 insertionsort.cpp)