#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct freedom - to free items
 * @buf: to free buffer
 * @filedes: to free file descrptors
 * @list_head: to free linked list
 *
 * Easy way to access to diferent kind of variable
 * en free malloc from them
 */
typedef struct freedom
{
	char *buf;
	FILE *filedes;
	stack_t *list_head;
} free_all;

/*Transform into global variable*/
extern free_all break_free;
free_all break_free;

/*Prototypes in function 4*/
void _pchar(stack_t **stack, unsigned int line_number);
void _pstr(stack_t **stack, unsigned int line_number);

/*Prototypes in function 3*/
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/*Prototypes in functions 2*/
void get_f(unsigned int line_number);
int check_number(char *data, unsigned int line_number);
void free_list(stack_t *stack);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/*Prototypes in functions*/
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);


#endif /* __MONTY_H__*/
