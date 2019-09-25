#include "monty_errors.h"
#include <errno.h>
#include "monty.h"
#include <unistd.h>

#define FILE_ERROR -1

int run_interpreter(char *filename)
{
	extern int errno;
	FILE *mfile;
	int access_check;
	int error_code;
	int file_processor_ret;

	access_check = access(filename, F_OK);
	if (access_check == FILE_ERROR)
	{
		error_code = errno;
		if (error_code == ENOENT)
			print_file_error(CANT_OPEN_FILE, filename);
	}
	else
	{
		mfile = fopen(filename, "r");
		file_processor_ret = file_processor(mfile);
		if (file_processor_ret == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
	}

	return (EXIT_FAILURE);
}
