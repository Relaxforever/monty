#include "monty.h"
#include "monty_errors.h"

/**
* _pop - eliminates the index one
* @stack: the list stack
* @line_number : the line number
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack != NULL)
	{
		(void) line_number;
		tmp = *stack;
		*stack = tmp->next;
		(*stack)->prev = NULL;
		free(tmp);
	}
	else
	{
		print_stack_error(PINT_STACK_EMPTY, line_number);
	}
}
