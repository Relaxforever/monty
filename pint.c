#include "monty_errors.h"
#include "monty.h"

void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head;

	if (ptr == NULL)
		error_processor(PINT_STACK_EMPTY, line_number);
	printf("%d", ptr->n);
}
