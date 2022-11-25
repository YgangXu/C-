cmake_minimum_required(VERSION 3.22)
project(ComputerRoomReservationSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComputerRoomReservationSystem main.cpp identity.h student.h student.cpp teacher.h teacher.cpp manager.h manager.cpp globalFile.h computerRoom.h orderFile.h orderFile.cpp)
