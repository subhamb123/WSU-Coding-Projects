cmake_minimum_required(VERSION 3.20)
project(Matching_Game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

add_executable(Matching_Game main.cpp definitions.cpp header.h)

FILE(COPY commands.csv DESTINATION "${CMAKE_BINARY_DIR}")
FILE(COPY profiles.csv DESTINATION "${CMAKE_BINARY_DIR}")