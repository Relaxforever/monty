#include "monty.h"
/**
* mega_free - Dabs on all the memory leaks
* Return: my Ego.
*/
void mega_free(void)
{
	menu **head = ctx.head;
	stack_t **st_head = ctx.stack;

	if (ctx.file != NULL)
		fclose(ctx.file);
	if (ctx.buffer != NULL)
		free(ctx.buffer);
	if (ctx.head != NULL)
	{
		free_opcodelist(*head);
		free(head);
	}
	if (st_head != NULL)
	{
		free_stack(*st_head);
		free(st_head);
	}
}
