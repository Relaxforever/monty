#include "monty_errors.h"
#include "monty.h"

void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *top, *second, *link;

	top = *head;
	second = top->next;

	if (top == NULL || second == NULL)
		error_processor(SWAP_SHORT_FAILURE, line_number);

	link = second->next;
	top->next = link;
	top->prev = second;
	second->prev = NULL;
	second->next = top;
	*head = second;
}