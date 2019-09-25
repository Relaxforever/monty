#include "monty.h"
#include "monty_errors.h"

int file_processor(FILE *file)
{
	menu **opcodes;
	// static int pushval = 0;
	size_t getline_size = 0;
	char *line_buffer = NULL;

	opcodes = opcode_list();

	while (!feof(file))
	{
		if (opcodes == NULL)
		{
			fclose(file);
			if (line_buffer != NULL)
				free(line_buffer);
			print_file_error(MALLOC_FAILURE, NULL);
		}
		getline(&line_buffer, &getline_size, file);
		printf("%s",line_buffer);
	}

	fclose(file);
	free(line_buffer);
	free_opcodelist(*opcodes);
	free(opcodes);
	return (0);
}
