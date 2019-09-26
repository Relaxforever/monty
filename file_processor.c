#include "monty.h"
#include "monty_errors.h"
#include <string.h>

int file_processor(FILE *file)
{
	menu **opcodes, *operation;
	extern int pushval;
	size_t getline_size = 0;
	char *line_buffer = NULL, *token, *arg;
	unsigned int line_number = 0;

	opcodes = opcode_list();
	if (opcodes == NULL)
	{
		fclose(file);
		print_file_error(MALLOC_FAILURE, NULL);
	}
	while (getline(&line_buffer, &getline_size, file) != EOF)
	{
		token = strtok(line_buffer, " \n\r\t\a");
		if (token != NULL)
		{
			arg = strtok(NULL, " \n\r\t\a");
			operation = isa_opcode(opcodes, token);
			if (operation != NULL) {
				if (operation->n_args == 1) {
					printf("%d\n",pushval);
					printf("%s", arg);
				}
			} else {
				print_instr_error(INVALID_INSTRUCTION, line_number, token);
			}
		}
		line_number++;
	}
	mega_free(file, line_buffer, opcodes);
	return (0);
}
