#include "monty.h"

/**
 * _pchar - function to print character from node
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n <= 0 || (*stack)->n >= 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	else
	{
		putchar((*stack)->n);
		putchar(10);
	}

}

/**
 * _pstr - function to print string from node
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	while ((*stack) && (*stack)->n > 0 && (*stack)->n <= 127)
	{
		putchar((*stack)->n);
		(*stack) = (*stack)->next;
	}
	putchar(10);

}
