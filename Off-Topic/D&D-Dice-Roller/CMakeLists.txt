cmake_minimum_required(VERSION 3.10)
project(D_D_Dice_Roller)

set(CMAKE_CXX_STANDARD 17)

add_executable(D_D_Dice_Roller main.cpp Utils/Dicer.cpp Utils/Dicer.h)