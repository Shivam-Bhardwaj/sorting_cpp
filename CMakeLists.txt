cmake_minimum_required(VERSION 3.15)
project(sort)

set(CMAKE_CXX_STANDARD 11)

add_executable(sort main.cpp mSort.cpp mSort.h utility.cpp utility.h qSort.cpp qSort.h fast.cpp fast.h)