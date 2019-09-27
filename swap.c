#include "monty_errors.h"
#include "monty.h"
/**
* _swap - swaps the whole thing
* @head: the stack list
* @line_number: the number of lines
*/
void _swap(stack_t **head, unsigned int line_number)
{
	int top;

	if (*head == NULL || (*head)->next == NULL)
		error_processor(SWAP_SHORT_FAILURE, line_number);
	(void) line_number;
	top = (*head)->next->n;
	(*head)->next->n = (*head)->n;
	(*head)->n = top;
}
