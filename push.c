#include "monty.h"
#include "monty_errors.h"

/**
*_push - adds a node at the beginning of the list
*@head: the head of the node
*@line_number: the line number that will be added.
*Return: the list with the new node
*/
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *ptr;

	if (ctx.arg)
	{
		if (isa_number(ctx.arg) == 1)
		{
			(void) line_number;
			ptr = malloc(sizeof(stack_t));
			if (ptr == NULL)
			{
				print_file_error(MALLOC_FAILURE, NULL);
			}
			ptr->n = atoi(ctx.arg);
			ptr->next = (*head);
			ptr->prev = NULL;
			if (*head != NULL)
				(*head)->prev = ptr;
			*head = ptr;
		}
		else
			print_arg_error(PUSH_FAILURE, line_number);
	}
	else
		print_arg_error(PUSH_FAILURE, line_number);
}
