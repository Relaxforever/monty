#include "monty_errors.h"
#include "monty.h"
/**
* _swap - swaps the whole thing
* @head: the stack list
* @line_number: the number of lines
*/
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *top;

	if (top == NULL || second == NULL)
		error_processor(SWAP_SHORT_FAILURE, line_number);
	(void) line_number;
	top = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = top;
}
