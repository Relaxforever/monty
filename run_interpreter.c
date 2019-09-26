#include "monty_errors.h"
#include "monty.h"
#include <unistd.h>

#define FILE_ERROR -1
/**
* run_interpreter - runs the interpreter
* @filename: the filename
* Return: Always Zero!
*/
int run_interpreter(char *filename)
{
	FILE *mfile;
	int access_check;
	int file_processor_ret;

	access_check = access(filename, F_OK);
	if (access_check == FILE_ERROR)
		print_file_error(CANT_OPEN_FILE, filename);
	else
	{
		mfile = fopen(filename, "r");
		file_processor_ret = file_processor(mfile);
		if (file_processor_ret == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}

	return (EXIT_FAILURE);
}
