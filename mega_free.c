#include "monty.h"

void mega_free(FILE *file, char *buffer, menu **head)
{
	if (file != NULL)
		fclose(file);
	if (buffer != NULL)
		free(buffer);
	if (head != NULL)
	{
		free_opcodelist(*head);
		free(head);
	}
}
