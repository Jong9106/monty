#include "monty.h"

/**
 *get_f - output format
 *@line_number: line number from monty file
 */
void get_f(unsigned int line_number)
{
	int same = 0;
	char *opcode = NULL;
	unsigned int j = 0;

	instruction_t options[] = {
		{"push", _push}, {"pall", _pall}, {"pint", _pint}, {"pop", _pop},
		{"swap", _swap}, {"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"pstr", _pstr}, {NULL, NULL}
	};

	opcode = strtok(break_free.buf, " ");

	if (opcode && opcode[0] != '#')
	{
		for (j = 0 ; options[j].opcode ; j++)
		{
			same = strcmp(options[j].opcode, opcode);
			if (same == 0)
			{
				options[j].f(&break_free.list_head, line_number);
				break;
			}
		}
	}

	if (options[j].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
}

/**
 * check_number - Free memory from a list
 * @data: pointer to head node
 * @line_number: line from monty file
 * Return: data into integer
 */
int check_number(char *data, unsigned int line_number)
{
	int i = 0;

	if (data == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(break_free.buf);
		free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}

	if (data[i] == '-')
		i++;
	for (; data[i] != '\0' ; i++)
	{
		if (data[i] < '0' || data[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(break_free.buf);
			free_list(break_free.list_head);
			fclose(break_free.filedes);
			exit(EXIT_FAILURE);
		}
	}
	return (atoi(data));
}

/**
 * free_list - Free memory from a list
 * @stack: pointer to head node
 */
void free_list(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * _add - function to add data from nodes
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}

	temp->next->n = (*stack)->n + (*stack)->next->n;
	(*stack) = temp->next;

	free(temp);

}

/**
 * _nop - function to do nothing
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

