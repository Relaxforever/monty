#include "monty.h"
#include "monty_errors.h"

int file_processor(FILE *file)
{
	menu **opcodes;
	extern int pushval;
	size_t getline_size = 0;
	char *line_buffer = NULL;

	opcodes = opcode_list();
	if (opcodes == NULL)
	{
		fclose(file);
		print_file_error(MALLOC_FAILURE, NULL);
	}

	while (getline(&line_buffer, &getline_size, file) != EOF)
	{
		pushval = 1;
		printf("%s",line_buffer);
		printf("%d\n", pushval);
	}

	fclose(file);
	free(line_buffer);
	free_opcodelist(*opcodes);
	free(opcodes);
	return (0);
}
