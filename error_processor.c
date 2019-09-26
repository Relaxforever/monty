#include "monty.h"
#include "monty_errors.h"

void error_processor(int oper_errno, unsigned int line)
{
	switch (oper_errno)
	{
		case PUSH_FAILURE:
			mega_free();
			print_arg_error(PUSH_FAILURE, line);
			break;
		case INVALID_INSTRUCTION:
			mega_free();
			print_instr_error(INVALID_INSTRUCTION, line, ctx.token);
			break;
		case MALLOC_FAILURE:
			mega_free();
			print_file_error(MALLOC_FAILURE, NULL);
			break;
		case PINT_STACK_EMPTY:
			mega_free();
			print_stack_error(PINT_STACK_EMPTY, line);
			break;
		case POP_STACK_EMPTY:
			mega_free();
			print_stack_error(POP_STACK_EMPTY, line);
			break;
		case SWAP_SHORT_FAILURE:
			mega_free();
			print_short_failures(SWAP_SHORT_FAILURE, line);
			break;
		case ADD_SHORT_FAILURE:
			mega_free();
			print_short_failures(ADD_SHORT_FAILURE, line);
			break;
		default:
			break;
	}
}
