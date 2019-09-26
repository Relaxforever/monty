#include "monty.h"
#include "monty_errors.h"
#include <string.h>

int file_processor(FILE *file)
{
	menu **opcodes, *operation;
	context ctx;
	size_t getline_size = 0;
	char *line_buffer = NULL, *token, *arg;
	unsigned int line_number = 0;

	opcodes = opcode_list();
	if (opcodes == NULL)
	{
		fclose(file);
		print_file_error(MALLOC_FAILURE, NULL);
	}
	ctx.token = NULL;
	ctx.arg = NULL;
	ctx.file = file;
	ctx.buffer = NULL;
	ctx.head = opcodes;
	while (getline(&line_buffer, &getline_size, file) != EOF)
	{
		ctx.buffer = line_buffer;
		token = strtok(line_buffer, " \n\r\t\a");
		ctx.token = token;
		if (token != NULL) //CHECK IF IS NOT A BLANK
		{
			arg = strtok(NULL, " \n\r\t\a");
			ctx.arg = arg;
			operation = isa_opcode(opcodes, token);
			if (operation != NULL)
				error_processor(run_operation(operation, arg), line_number, ctx);
			else
				error_processor(INVALID_INSTRUCTION, line_number, ctx);
		}
		line_number++;
	}
	mega_free(ctx);
	return (0);
}
