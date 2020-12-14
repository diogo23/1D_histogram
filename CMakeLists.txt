cmake_minimum_required(VERSION 3.15)
project(Histogram)

set(CMAKE_CXX_STANDARD 14)

add_executable(Histogram main.cpp include/Histrogram.cpp include/Histrogram.h include/utils/utils.h)