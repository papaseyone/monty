#include "monty.h"

/**
 * print_file_error - prints error message when file opening fails and exits
 * @file: name of file which failed to open
 */
void print_file_error(char *file)
{
	fprintf(stderr, "Error: Can't open file %s\n", file);
	exit(EXIT_FAILURE);
}

/**
 * print_usage_error - prints error message if incorrect argumnets are passed.
 */
void print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * print_malloc_error - prints error from failed malloc
 */
void print_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * check_arguments - checks that the arguments are numerical and prints error
 * @stack: pointer to stack
 * @line_number: line number op was read from script
 * @op: operation code
 * @arg: argument to be checked
 */
void check_arguments(stack_t **stack, unsigned int line_number, char *op, char *arg)
{
	unsigned int x, ln = line_number;

	for (x = 0; arg[x] != '\0'; x++)
	{
		if ((arg[x] < 48 || arg[x] > 57) && arg[x] != '-')
		{
			free_all_resources(stack, op, arg);
			fprintf(stderr, "L%u: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
	}
}
