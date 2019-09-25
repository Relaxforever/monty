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
		menu *tmp;
		unsigned int cont;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(menu));
	if (ptr == NULL)
		return (NULL);
	ptr->opcode = opname;
	ptr->n_args = n_args;
	ptr->next = NULL;
	if (*head == NULL)
	{
		*head = ptr;
		return (*head);
	}
	tmp = *head;
	for (cont = 0; tmp->next != NULL; cont++)
	{
		tmp = tmp->next;
	}
	tmp->next = ptr;
	return (*head);
}
/**
* opcode_list - creates the oplist
* THIS FUNCTIONS NEEDS FREE
*Return: a pointer filled with op codes
*/
menu **opcode_list(void)
{
	menu **head;

	head = malloc(sizeof(menu *) * 1);
	head = NULL;
	create_opstruct(head, "push", 1);
	if (*head == NULL)
		free_opcodelist(*head);
		return (NULL);
	if (create_opstruct(head, "pall", 0) == NULL)
		free_opcodelist(*head);
		return (NULL);
	if (create_opstruct(head, "pint", 0) == NULL)
		free_opcodelist(*head);
		return (NULL);
	if (create_opstruct(head, "pop", 0) == NULL)
		free_opcodelist(*head);
		return (NULL);
	if (create_opstruct(head, "swap", 0) == NULL)
		free_opcodelist(*head);
		return (NULL);
	if (create_opstruct(head, "add", 0) == NULL)
		free_opcodelist(*head);
		return (NULL);
	if (create_opstruct(head, "nop", 0) == NULL)
		free_opcodelist(*head);
		return (NULL);
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

int main (void)
{
	menu **opcode;
	int cont = 0;
	opcode = opcode_list();
	for (cont = 0; *opcode != NULL; cont++)
	{
		printf("%s is the name and %d",(*opcode)->opcode, (*opcode)->n_args);
		(*opcode) = (*opcode)->next;
	}
	return (0);
}
