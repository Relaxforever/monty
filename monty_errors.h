#ifndef _MONTY_ERRORS_H_
#define _MONTY_ERRORS_H_

#define FILE_NOT_FOUND 1
#define CANT_OPEN_FILE 2
#define INVALID_INSTRUCTION 3
#define MALLOC_FAILURE 4
#define PUSH_FAILURE 5
#define PINT_STACK_EMPTY 6
#define POP_STACK_EMPTY 7
#define SWAP_SHORT_FAILURE 8
#define ADD_SHORT_FAILURE 9
#define SUB_SHORT_FAILURE 10
#define MUL_SHORT_FAILURE 11
#define MOD_SHORT_FAILURE 12
#define MOD_DIVISION_ZERO 13
#define DIV_DIVISION_ZERO 14
#define DIV_SHORT_FAILURE 15

void print_file_error(int errno, char *filename);
void print_arg_error(int errno, unsigned int line);
void print_stack_error(int errno, unsigned int line);
void print_short_failures(int errno, unsigned int line);
void print_instr_error(int errno, unsigned int line);

#endif
