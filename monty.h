#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdlib.h>
#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
* struct menu_s - the menu that will be used to check
* @opcode: the opcode
* @n_args: the # of args
* @next: points to the next list
* @f: the functions
* Description: the menu that will be used to check if the f exist.
*/
typedef struct menu_s
{
		char *opcode;
		int n_args;
		struct menu_s *next;
		void (*f)(stack_t **stack, unsigned int line_number);
} menu;

typedef struct ctx_s
{
	unsigned int line;
	char *token;
	char *arg;
	FILE *file;
	char *buffer;
	menu **head;
	stack_t **stack;
} context;

extern context ctx;
int has_args(char *token);
int isa_number(char *token);
int run_interpreter(char *filename);
menu *create_opstruct(menu **head, char *opname, int n_args);
menu **opcode_list(void);
int file_processor(FILE *file);
void free_opcodelist(menu *head);
menu *isa_opcode(menu **oplist, char *token);
void mega_free(void);
int run_operation(menu *operation, char *argument);
char *_memset(char *s, char b, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void error_processor(int oper_errno, unsigned int line);
menu **failed_head(menu **head);
void free_stack(stack_t *head);
context ctx;

#endif
