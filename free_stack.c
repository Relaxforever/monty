#include "monty.h"
/**
*free_stack - frees all the list
*@head: the head that will be given
*/
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = NULL;
}
