cmake_minimum_required(VERSION 3.26)
project(C_Project_L2 C)

set(CMAKE_C_STANDARD 11)

add_executable(C_Project_L2 main.c
        level_cells.c
        level_cells.h
        level_lists.c
        level_lists.h)
