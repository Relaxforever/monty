#include "monty.h"
#include "monty_errors.h"

/**
* _pop - eliminates the index one
* @stack: the list stack
* @line_number : the line number
*/
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) line_number;
	if (*stack != NULL)
	{
		if (tmp->next != NULL)
		{
			(tmp->next)->prev = NULL;
			*stack = tmp->next;
			free(tmp);
		}
		else
		{
			*stack = NULL;
			free(tmp);
		}
	}
	else
	{
		print_stack_error(POP_STACK_EMPTY, line_number);
	}
}
