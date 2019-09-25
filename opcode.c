#include "monty.h"
#include "monty_errors.h"

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
menu **opcode_list(void)
{
		menu **head;
		int cont;

		head = malloc(sizeof(400));
		*head = NULL;
		create_opstruct(head, "push", 1);
		create_opstruct(head, "pall", 0);
		create_opstruct(head, "pint", 0);
		create_opstruct(head, "pop", 0);
		create_opstruct(head, "swap", 0);
		create_opstruct(head, "add", 0);
		create_opstruct(head, "nop", 0);
		/** recolalo con un for que funciona
		* con (*head) != NULL
		* falta cambiar el nombre de este main a
		* que sea una función que retorne una
		* lista
		*/
		return (head);
}
