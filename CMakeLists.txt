cmake_minimum_required(VERSION 3.27)
 
set(CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
 
project(Hanoi)
 
add_executable(Hanoi main.cpp pillar.cpp hanoi.cpp)