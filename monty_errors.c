#include "monty.h"
#include "monty_errors.h"
/**
* print_file_error - prints all the error messages
* @errno: the number of the error
* @filename: the name of the file
*/
void print_file_error(int errno, char *filename)
{
		switch (errno)
		{
				case FILE_NOT_FOUND:
										fprintf(stderr, "USAGE: monty file\n");
										exit(EXIT_FAILURE);
				case CANT_OPEN_FILE:
										fprintf(stderr, "Error: Can't open file %s\n", filename);
										exit(EXIT_FAILURE);
				case MALLOC_FAILURE:
										fprintf(stderr, "Error: malloc failed\n");
										exit(EXIT_FAILURE);
		}
}
/**
* print_arg_error - prints the other kind of errors
* @errno: the number of the error
* @line: the line of the error
*/
void print_arg_error(int errno, unsigned int line)
{
		switch (errno)
		{
				case PUSH_FAILURE:
								fprintf(stderr, "L%u: usage: push integer\n", line);
								exit(EXIT_FAILURE);
		}
}
/**
* print_stack_error - prints all error related to the stack
* @errno: the number of the error
* @line: the line number
*/
void print_stack_error(int errno, unsigned int line)
{
		switch (errno)
		{
				case PINT_STACK_EMPTY:
										fprintf(stderr, "L%u: can't pint, stack
										empty\n", line);
										exit(EXIT_FAILURE);
				case POP_STACK_EMPTY:
										fprintf(stderr, "L%u: can't pop an empty
										stack\n", line);
										exit(EXIT_FAILURE);
		}
}
/**
* print_short_failures - the error related to few elements
* @errno: the number of the error
* @line: the line number
*/
void print_short_failures(int errno, unsigned int line)
{
		switch (errno)
		{
				case SWAP_SHORT_FAILURE:
										fprintf(stderr, "L%u: can't
										swap, stack too short\n", line);
										exit(EXIT_FAILURE);
				case ADD_SHORT_FAILURE:
										fprintf(stderr, "L%u: can't
										add, stack too short\n", line);
										exit(EXIT_FAILURE);
		}
}
/**
* print_instr_error - errors related to instructions
* @errno: the number of the error
* @line: the line number
* @opcode: the name of the instruction
*/
void print_instr_error(int errno, unsigned int line, char *opcode)
{
		switch (errno)
		{
				case INVALID_INSTRUCTION:
										fprintf(stderr, "L%u: unknown
										instruction %s\n", opcode);
										exit(EXIT_FAILURE);
		}
}