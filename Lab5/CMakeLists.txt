cmake_minimum_required(VERSION 3.17)
project(Lab5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab5
        Iter_Alg.cpp
        Point.cpp
        Shape.cpp
        Rectangle.cpp)
