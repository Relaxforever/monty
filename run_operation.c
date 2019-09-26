#include "monty.h"
#include "monty_errors.h"

int run_operation(menu *operation, char *argument)
{
	printf("LINE: %u OPCODE: %s | ARGUMENT: %s\n", ctx.line, operation->opcode, argument);
	return (0);
}
