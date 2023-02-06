cmake_minimum_required(VERSION 3.0.0)
project(MatrixLibrary VERSION 0.1.0)

add_library(matrix STATIC Matrix/matrix.cpp )

add_executable(MatrixLibrary main.cpp)

target_link_libraries (MatrixLibrary matrix)

