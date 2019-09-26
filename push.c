#include "monty.h"
#include "monty_errors.h"
#include "operations.h"
/**
*push_numberstack - adds a node at the beginning of the list
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
	ptr->n = ctx.line;
	*head = ptr;
}
/**
* pall_numberstack - shows all the stack.
*@head: the list
*@line_number: the line number.
*/
void _pall(stack_t **head, unsigned int line_number)
{
	int cont = 0;
	stack_t *tmp;

	(void) line_number;
	tmp = *head;
	if (tmp != NULL)
	{
		for (tmp = 0; tmp != NULL; cont++)
		{
			printf("%d\n", tmp->n);
			tmp = tmp->next;
		}
	}
}
