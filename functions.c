#include "monty.h"
/**
 * _push - function to add a node at head
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char *data;
	unsigned int number = 0;
	stack_t *new_node;

	(void)line_number;

	data = strtok(NULL, " ");

	number = check_number(data, line_number);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * _pall - function that prints all the elements of a list
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - function to print data form head
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - function to delete head node
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	free(temp);
}

/**
 * _swap - function to swap data from nodes
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int data = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
