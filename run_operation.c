#include "monty.h"
/**
* run_operation - runs the whole operations
* @operation: the operation given.
* @argument: the argument given
* Return: Always Zero!
*/
int run_operation(menu *operation, char *argument)
{
	(void) operation;
	(void) argument;
	operation->f(ctx.stack, ctx.line);
	return (0);
}
