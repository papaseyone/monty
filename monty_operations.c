#include "monty.h"

/**
 * divide_top_two_elements -  divides the second stack element by the top element and
 * removes the top element euqting the second to th result.
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void divide_top_two_elements(stack_t **stack, unsigned int line_number)
{
	unsigned int num = line_number;
	int integer;
	stack_t *prev, *temp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't div, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	prev = (*stack)->prev;
	integer = prev->n / (*stack)->n;
	prev->n = integer;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
 * modulo_top_two_elements - finds the remainder from division of the top two elements
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void modulo_top_two_elements(stack_t **stack, unsigned int line_number)
{
	unsigned int num = line_number;
	int integer;
	stack_t *prev, *temp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't mod, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	prev = (*stack)->prev;
	integer = prev->n % (*stack)->n;
	prev->n = integer;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
 * print_char -  prints the char at the top of the stack
 * @stack: pointer to top of stack
 * @line_number: line number operation was read from script
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	unsigned int l_n = line_number;

	if (*stack == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't print_char, stack empty\n", l_n);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't print_char, value out of range\n", l_n);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * print_string -  prints the string starting at the top of the stack
 * @stack: pointer to top of stack
 * @line_number: line number operation was read from script
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack);

	(void) line_number;
	while (temp != NULL)
	{
		if (temp->n < 1 || temp->n > 127)
			break;
		putchar(temp->n);
		temp = temp->prev;
	}
	putchar('\n');
}
