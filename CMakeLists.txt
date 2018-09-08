cmake_minimum_required(VERSION 3.10)
project(type-traits-gmsh2334)

set(CMAKE_CXX_STANDARD 11)

add_executable(type-traits-gmsh2334 main.cpp iterator.h node.h dlist.h slist.h)