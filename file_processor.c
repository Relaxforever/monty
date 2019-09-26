#include "monty.h"
#include "monty_errors.h"
#include <string.h>
/**
* file_processor - file processor
* @file: doing the file
* Return: 0 perro
*/
int file_processor(FILE *file)
{
	menu **opcodes, *operation;
	size_t getline_size = 0;
	char *line_buffer = NULL, *token, *arg;
	unsigned int line_number = 1;
	stack_t **st = _calloc(1, sizeof(stack_t *));

	opcodes = opcode_list();
	if (opcodes == NULL || st == NULL)
	{
		fclose(file);
		print_file_error(MALLOC_FAILURE, NULL);
	}
	ctx.token = NULL;
	ctx.arg = NULL;
	ctx.file = file;
	ctx.buffer = NULL;
	ctx.head = opcodes;
	ctx.line = line_number;
	ctx.stack = st;
	while (getline(&line_buffer, &getline_size, file) != EOF)
	{
		ctx.buffer = line_buffer;
		token = strtok(line_buffer, " \n\r\t\a");
		ctx.token = token;
		if (token != NULL) /*CHECK IF IS NOT A BLANK*/
		{
			arg = strtok(NULL, " \n\r\t\a");
			ctx.arg = arg;
			operation = isa_opcode(opcodes, token);
			if (operation != NULL)
				error_processor(run_operation(operation, arg), line_number);
			else
				error_processor(INVALID_INSTRUCTION, line_number);
		}
		line_number++;
		ctx.line = line_number;
	}
	mega_free();
	return (0);
}
