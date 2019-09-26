#include "monty.h"

void mega_free(void)
{
	menu **head = ctx.head;

	if (ctx.file != NULL)
		fclose(ctx.file);
	if (ctx.buffer != NULL)
		free(ctx.buffer);
	if (ctx.head != NULL)
	{
		free_opcodelist(*head);
		free(head);
	}
}
