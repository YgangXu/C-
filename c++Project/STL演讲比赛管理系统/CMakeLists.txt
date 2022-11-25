cmake_minimum_required(VERSION 3.22)
project(STL)

set(CMAKE_CXX_STANDARD 14)

add_executable(STL main.cpp speechManager.cpp speechManager.h speaker.h)
