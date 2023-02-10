cmake_minimum_required(VERSION 3.14.0)
project(MatrixLibrary VERSION 0.0.5 DESCRIPTION "A C++ 23 Matrix Library")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-pedantic -Wall -Wextra -Werror -Wshadow -Wsign-conversion -g -O2)

add_library(matrix Matrix/matrix.cpp )

add_executable(MatrixLibrary main.cpp)

target_link_libraries (MatrixLibrary matrix)

