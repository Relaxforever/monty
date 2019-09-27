#include "monty_errors.h"
#include "monty.h"
#include "operations.h"
/**
* _sub - adds two numbers
* @head: the lsit head
* @line_number: the line number
*/
void _sub(stack_t **head, unsigned int line_number)
{
	int a, b, ans;

	if ((*head) == NULL || (*head)->next == NULL)
		error_processor(SUB_SHORT_FAILURE, line_number);
	a = (*head)->n;
	b = (*head)->next->n;
	ans = b - a;
	(*head)->next->n = ans;
	_pop(head, line_number);
}
