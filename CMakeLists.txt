# cmake_minimum_required(VERSION <specify CMake version here>)
project(stockControl)

set(CMAKE_CXX_STANDARD 14)

add_executable(stockControl main.cpp Produto.h Estoque.h Fila.h)