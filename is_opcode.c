#include "monty.h"
#include "monty_errors.h"
#include <string.h>
/**
* isa_opcode - checks if token is a opecode
* @oplist: the list of the op codes
* @token: the token with the name
* Return: One if it is and zero.
*/
menu *isa_opcode(menu **oplist, char *token)
{
	menu *tmp;
	unsigned int count;

	tmp = *oplist;
	for (count = 0; tmp != NULL; count++)
	{
		if (strcmp(tmp->opcode, token) == 0)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
