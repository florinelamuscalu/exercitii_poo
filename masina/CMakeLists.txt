cmake_minimum_required(VERSION 3.17)
project(masina)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Weffc++")
add_executable(masina main.cpp)