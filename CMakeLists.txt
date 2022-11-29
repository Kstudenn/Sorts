cmake_minimum_required(VERSION 3.9)
project(Sortowanie_2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Sortowanie_2 main.cpp Table/Table.cpp Headers/Table.hpp Sort/QuickSort.cpp Headers/QuickSort.hpp Sort/IntroSort.cpp Sort/MergeSort.cpp Headers/MergeSort.hpp Headers/IntroSort.hpp)