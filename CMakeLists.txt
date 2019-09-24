cmake_minimum_required(VERSION 3.14)
project(monty)

set (CMAKE_C_FLAGS "-g -ggdb -Wall -Werror -Wextra -pedantic")

include_directories(.)

add_executable(monty
        main.c
        monty.h
)
