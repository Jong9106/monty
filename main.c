#include "monty.h"
/**
 *get_f - output format
 *@line_number: line number from monty file
 */
void get_f(unsigned int line_number)
{
	int same = 0;
	char *opcode = NULL;

	opcode = strtok(break_free.buf, " ");

	instruction_t options[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	unsigned int j = 0;

	for (j = 0 ; options[j].opcode ; j++)
	{
		same = strcmp(options[j].opcode, opcode);
		if (same == 0)
		{
			options[j].f(&break_free.list_head, line_number);
			return;
		}
	}
	fprintf(stderr, "L %u: unknown instruction %s\n", line_number, opcode);
	free(break_free.buf);
	free_list(break_free.list_head);
	fclose(break_free.filedes);
	exit(EXIT_FAILURE);
}

/**
 * main - Program to read and execute monty file
 * @argc: number of arguments
 * @argv: arguments from prompt
 * Return: Allways 0 to success
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	size_t bytes;

	break_free.buf = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	break_free.filedes = fopen(argv[1], "r");

	if (break_free.filedes == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&break_free.buf, &bytes, break_free.filedes) != EOF &&
			++line_number)
		get_f(line_number);

	free(break_free.buf);
	free_list(break_free.list_head);
	fclose(break_free.filedes);
	exit(EXIT_SUCCESS);
}
