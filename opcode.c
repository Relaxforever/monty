#include "monty.h"
#include "monty_errors.h"
/**
* create_opstruct - creates the opcode structure
* @head: the head of the list
* @opname: the name of the opcode
* @n_args: the number of arguments
* Return: the address of the created list
*/
menu *create_opstruct(menu **head, char *opname, int n_args)
{
		menu *ptr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(menu));
	if (ptr == NULL)
		return (NULL);
	if (*head == NULL)
	{
		*head = ptr;
		ptr->opcode = opname;
		ptr->n_args = n_args;
		ptr->next = NULL;
	}
	ptr->next = *head;
	ptr->opcode = opname;
	ptr->n_args = n_args;
	*head = ptr;
	return (ptr);
}
/**
* opcode_list - creates the oplist
* THIS FUNCTIONS NEEDS FREE
*Return: a pointer filled with op codes
*/
menu **opcode_list(void)
{
	menu **head;

	*head = NULL;
	create_opstruct(head, "push", 1);
	create_opstruct(head, "pall", 0);
	create_opstruct(head, "pint", 0);
	create_opstruct(head, "pop", 0);
	create_opstruct(head, "swap", 0);
	create_opstruct(head, "add", 0);
	create_opstruct(head, "nop", 0);
	return (head);
}
/**
*free_opcodelist - frees all the list
*@head: the head that will be given
*/
void free_opcodelist(menu *head)
{
	menu *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	head = NULL;
}
