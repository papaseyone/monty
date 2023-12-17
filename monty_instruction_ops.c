#include "monty.h"

/**
 * print_top_stack_element - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void print_top_stack_element(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap_top_two_elements - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void swap_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *prev, *temp = *stack;
	unsigned int num = line_number;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	prev = (*stack)->prev;
	prev->next = NULL;
	temp->prev = prev->prev;
	if (prev->prev != NULL)
		prev->prev->next = temp;
	prev->prev = temp;
	temp->next = prev;
	*stack = prev;
}

/**
 * add_top_two_elements -  adds the top two elements of the stack_
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	unsigned int num = line_number;
	int integer;
	stack_t *prev, *temp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	prev = (*stack)->prev;
	integer = prev->n + (*stack)->n;
	prev->n = integer;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
 * subtract_top_two_elements -  subtracts the top two elements of the stack_
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void subtract_top_two_elements(stack_t **stack, unsigned int line_number)
{
	unsigned int num = line_number;
	int integer;
	stack_t *prev, *temp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't sub, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	prev = (*stack)->prev;
	integer = prev->n - (*stack)->n;
	prev->n = integer;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}

/**
 * multiply_top_two_elements -  multiplies the top two elements of the stack to form 2nd.
 * @stack: pointer to stack
 * @line_number: line number read from script
 */
void multiply_top_two_elements(stack_t **stack, unsigned int line_number)
{
	unsigned int num = line_number;
	int integer;
	stack_t *prev, *temp = *stack;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		free_all_resources(stack, NULL, NULL);
		fprintf(stderr, "L%u: can't mul, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
	prev = (*stack)->prev;
	integer = prev->n * (*stack)->n;
	prev->n = integer;
	prev->next = NULL;
	*stack = prev;
	free(temp);
}
