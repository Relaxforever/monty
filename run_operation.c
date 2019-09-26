#include "monty.h"

int run_operation(menu *operation, char *argument)
{
	(void) operation;
	(void) argument;
	operation->f(ctx.stack, ctx.line);
	return (0);
}
