#include "monty.h"
#include "operations.h"
/**
* create - creates the opcode structure
* @h: the head of the list
* @o: the name of the opcode
* @n: the number of arguments
* @f: function pointer.
* Return: the address of the created list
*/
menu *create(menu **h, char *o, int n, void (*f)(stack_t **s, unsigned int l))
{
		menu *ptr;
		menu *tmp;
		unsigned int cont;

	if (h == NULL)
		return (NULL);
	ptr = malloc(sizeof(menu));
	if (ptr == NULL)
		return (NULL);
	ptr->opcode = o;
	ptr->n_args = n;
	ptr->f = f;
	ptr->next = NULL;
	if (*h == NULL)
	{
		*h = ptr;
		return (*h);
	}
	tmp = *h;
	for (cont = 0; tmp->next != NULL; cont++)
	{
		tmp = tmp->next;
	}
	tmp->next = ptr;
	return (*h);
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
	*head = NULL;
	if (create(head, "push", 1, _push) == NULL)
		failed_head(head);
	if (create(head, "pall", 0, _pall) == NULL)
		failed_head(head);
	if (create(head, "pint", 0, _pint) == NULL)
		failed_head(head);
	if (create(head, "pop", 0, _pop) == NULL)
		failed_head(head);
	if (create(head, "swap", 0, _swap) == NULL)
		failed_head(head);
	if (create(head, "add", 0, _add) == NULL)
		failed_head(head);
	if (create(head, "nop", 0, _nop) == NULL)
		failed_head(head);
	if (create(head, "sub", 0, _sub) == NULL)
		failed_head(head);
	if (create(head, "mul", 0, _mul) == NULL)
		failed_head(head);
	if (create(head, "div", 0, _div) == NULL)
		failed_head(head);
	if (create(head, "mod", 0, _mod) == NULL)
		failed_head(head);
	if (create(head, "#", 0, _nop) == NULL)
		failed_head(head);
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
/**
* Failed_head - check if head failed
* @head: the list
* Return: NULL IF failed
**/
menu **failed_head(menu **head)
{
	free_opcodelist(*head);
	return (NULL);
}
/*
*int main(void)
*{
*	menu **alo;
*	int cont;
*
*	alo = opcode_list();
*	for (cont = 0; (*alo) != NULL; cont++)
*	{
*		printf("%s and %d\n",(*alo)->opcode, (*alo)->n_args);
*		(*alo) = (*alo)->next;
*	}
*	return (0);
*}
*/
