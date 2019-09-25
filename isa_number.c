#include "monty.h"
#include "monty_errors.h"
#include <ctype.h>
/**
* isa_number - checks if a token is a number
* @token: the token that will be check
*Return: 1 if it's a number or zero if isn't
*/
int isa_number(char *token)
{
	if (isdigit(*token) > 0)
	{
		return (1);
	}
	return (0);
}
