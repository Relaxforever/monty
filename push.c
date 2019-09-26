#include "monty.h"
#include "monty_errors.h"
#include "operations.h"
/**
*_push - adds a node at the beginning of the list
*@head: the head of the node
*@line_number: the line number that will be added.
*Return: the list with the new node
*/
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	(void) line_number;
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		print_file_error(MALLOC_FAILURE, NULL);
	}
	if (*head != NULL)
	{
		(*head)->prev = ptr;
		ptr->next = *head;
		(*head)->next = NULL;
	}
	if (*head == NULL)
	{
		*head = ptr;
		ptr->next = NULL;
	}
	ptr->prev = NULL;
	ptr->n = ctx.arg;
	*head = ptr;
}
