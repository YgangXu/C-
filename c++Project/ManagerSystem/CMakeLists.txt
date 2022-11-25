cmake_minimum_required(VERSION 3.22)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ main.cpp workerManager.h workerManager.cpp worker.h employee.h employee.cpp manager.h manager.cpp boss.h boss.cpp)
