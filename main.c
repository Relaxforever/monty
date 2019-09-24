#include "monty.h"
#include "monty_errors.h"
#include <stdio.h>

/**
 * main - Entry point to monty
 * @argc: Arg count
 * @argv: Arg vector
 * Return: Always cero!
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		print_file_error(FILE_NOT_FOUND, NULL);

	run_interpreter(argv[1]);
	return (0);
}
