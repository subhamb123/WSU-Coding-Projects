cmake_minimum_required(VERSION 3.20)
project(AVL_Trees)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

add_executable(AVL_Trees main.cpp AVLNode.h AVLTree.h)