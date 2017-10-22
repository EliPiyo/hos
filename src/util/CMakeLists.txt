cmake_minimum_required(VERSION 3.9.4)
add_definitions("-Wall -std=c++11")
add_library(util STATIC
  slow_console.hpp
  slow_console.cpp
)