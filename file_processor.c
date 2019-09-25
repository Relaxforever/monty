#include "monty.h"
#include "monty_errors.h"

int file_processor(FILE *file)
{
	menu **opcodes;
	// static int pushval = 0;
	size_t getline_size = 0;
	char *line_buffer;

	while (!feof(file))
	{
		line_buffer = malloc(1024);
		opcodes = opcode_list();
		if (line_buffer == NULL || opcodes == NULL)
		{
			fclose(file);
			print_file_error(MALLOC_FAILURE, NULL);
		}
		getline(&line_buffer, &getline_size, file);
		printf("%s",line_buffer);
	}

	fclose(file);
	free_opcodelist(*opcodes);
	free(opcodes);
	return (0);
}
