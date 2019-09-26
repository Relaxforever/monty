#include "monty_errors.h"
#include "monty.h"
#include "operations.h"

void _add(stack_t **head, unsigned int line_number)
{
	int a, b, ans;

	if (head == NULL || (*head)->next == NULL)
		error_processor(ADD_SHORT_FAILURE, line_number);

	a = (*head)->n;
	b = (*head)->next->n;

	ans = a + b;

	_pop(head, line_number);
	(*head)->n = ans;
}

