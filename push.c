#include "monty.h"
#include "monty_errors.h"
/**
*push_numberstack - adds a node at the beginning of the list
*@head: the head of the node
*@n: the number that will be added.
*Return: the list with the new node
*/
stack_t *push_numberstack(stack_t **head, const int n)
{
		stack_t *ptr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		print_file_error(MALLOC_FAILURE, NULL);
	if (*head == NULL)
	{
		*head = ptr;
		ptr->n = n;
		ptr->next = NULL;
		ptr->prev = NULL;
		return (ptr);
	}
	if (*head != NULL)
	{
		(*head)->prev = ptr;
	}
	ptr->next = *head;
	ptr->prev = NULL;
	ptr->n = n;
	*head = ptr;
	return (ptr);
}
