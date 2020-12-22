#include "monty.h"

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
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&break_free.buf, &bytes, break_free.filedes) != EOF &&
			++line_number)
	{
		if (break_free.buf)
		{
			break_free.buf[strlen(break_free.buf) - 1] = '\0';
			get_f(line_number);
		}
	}

	free(break_free.buf);
	free_list(break_free.list_head);
	fclose(break_free.filedes);
	exit(EXIT_SUCCESS);
}
