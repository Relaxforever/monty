#include "monty_errors.h"
#include "monty.h"
#include "operations.h"
/**
* _mod - adds two numbers
* @head: the lsit head
* @line_number: the line number
*/
void _mod(stack_t **head, unsigned int line_number)
{
	int a, b, ans;

	if ((*head) == NULL || (*head)->next == NULL)
		error_processor(DIV_SHORT_FAILURE, line_number);
	a = (*head)->n;
	b = (*head)->next->n;
	if (b == 0)
		error_processor(DIV_DIVISION_ZERO, line_number);
	if (a == 0)
		ans = 0;
	else
		ans = b % a;
	(*head)->next->n = ans;
	_pop(head, line_number);
}
