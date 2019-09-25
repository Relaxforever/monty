#include "monty.h"
#include "monty_errors.h"

int file_processor(FILE *file)
{
	menu **opcodes;
	static int pushval = 0;
	size_t getline_size = 0;
	char *line_buffer;
	int ready = 1;

	while (ready)
	{
		line_buffer = malloc(1024);


	}


	opcodes = opcode_list();
}