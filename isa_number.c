#include "monty.h"
#include "monty_errors.h"
#include <ctype.h>
/**
* isa_number - checks if a token is a number
* @token: the token that will be check
* Return: 1 if it's a number or zero if isn't
*/
int isa_number(char *token)
{
	int i = 0;
	int zero = 48;
	int nine = 57;
	int min = 45;

	if (token[i] == min || (token[i] >= zero && token[i] <= nine))
	{
		for (i = 1; token[i] != '\0'; i++)
		{
			if (token[i] >= zero && token[i] <= nine)
			{
				continue;
			}
			else
			{
				return (0);
			}
		}
		return (1);
	}
	return (0);
}
