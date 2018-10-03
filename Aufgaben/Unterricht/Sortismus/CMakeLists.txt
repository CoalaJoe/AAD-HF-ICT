cmake_minimum_required(VERSION 3.12)
project(Sortismus)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sortismus main.cpp Sort.cpp Sort.h InsertionSort.cpp InsertionSort.h)