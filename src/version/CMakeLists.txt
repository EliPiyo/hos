cmake_minimum_required(VERSION 3.9.4)
add_definitions("-Wall -std=c++11")
add_library(version STATIC
  version.hpp
  version.cpp
)