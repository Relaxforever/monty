#include "monty.h"
#include "monty_errors.h"

int run_operation(menu *operation, char *argument)
{
	printf("OPCODE: %s | ARGUMENT: %s\n", operation->opcode, argument);
	return (0);
}
