cmake_minimum_required(VERSION 3.24)
project(DA2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DA2
        src/main.cpp src/menu.cpp src/CSVReader.cpp header/CSVReader.h header/Graph.h src/Graph.cpp)
