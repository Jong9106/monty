#include "monty.h"

/**
 * _sub - function to sub data from nodes
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}

	temp->next->n = (*stack)->next->n - (*stack)->n;
	(*stack) = temp->next;

	free(temp);

}

/**
 * _div - function to  divide data from nodes
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}

	temp->next->n = (*stack)->next->n / (*stack)->n;
	(*stack) = temp->next;

	free(temp);

}

/**
 * _mul - function to multiply data from nodes
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}

	temp->next->n = (*stack)->next->n * (*stack)->n;
	(*stack) = temp->next;

	free(temp);

}

/**
 * _mod - function to  divide data from nodes
 * @stack: pointer to head pointer
 * @line_number: line from monty file
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(break_free.buf);
		if (break_free.list_head)
			free_list(break_free.list_head);
		fclose(break_free.filedes);
		exit(EXIT_FAILURE);
	}

	temp->next->n = (*stack)->next->n % (*stack)->n;
	(*stack) = temp->next;

	free(temp);

}

