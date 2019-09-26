cmake_minimum_required(VERSION 3.14)
project(monty)

set(CMAKE_C_FLAGS "-g -ggdb -Wall -Werror -Wextra -pedantic")

include_directories(.)

add_executable(monty
        main.c
        monty.h
        monty_errors.c
        monty_errors.h
        run_interpreter.c
        opcode.c
        push.c
        pall.c
        file_processor.c
        isa_number.c
        is_opcode.c
        mega_free.c
        run_operation.c
        _calloc.c
        error_processor.c
        operations.h
)
