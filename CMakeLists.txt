cmake_minimum_required(VERSION 3.29)

set(CMAKE_MAKE_PROGRAM "D:/Program Files/mingw64/bin/make.exe")
set(CMAKE_C_COMPILER "D:/Program Files/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Program Files/mingw64/bin/g++.exe")

project(main)

add_executable(main ./source/main.cpp ./source/initialize.cpp ./source/discretization.cpp ./source/control.cpp)
