#include "monty.h"
#include "monty_errors.h"
/**
* _pall - shows all the stack.
*@head: the list
*@line_number: the line number.
*/
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
