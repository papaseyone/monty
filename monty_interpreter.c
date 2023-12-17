#include "monty.h"

/**
 * free_all_resources - frees dynamic allocated memory
 * @stack:stack linked list
 * @opcode: operation code
 * @arg: argument to opcode if available
 */
void free_all_resources(stack_t **stack, char *opcode, char *arg)
{
	if (arg != NULL)
		free(arg);
	if (opcode != NULL)
		free(opcode);
	free_stack_memory(*stack);
	free_instructions();
}

/**
 * perform_push - performs the push operation
 * @stack: pointer to stack
 * @arg: arg to push
 * @ln: line number read from script
 * @opcode: operation code "push"
 * @mod: current mode of the program; stack or queue
 *
 * Return: nothing
 */
void perform_push(stack_t **stack, char *arg, ssize_t ln, char *opcode, ssize_t mod)
{
	int num = atoi(arg);
	stack_t *new, *last = *stack;

	if (arg == NULL)
	{
		free_all_resources(stack, opcode, arg);
		fprintf(stderr, "L%lu: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	check_arguments(stack, ln, opcode, arg);
	new = (stack_t *) malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_all_resources(stack, opcode, arg);
		print_malloc_error();
	}
	new->n = num;
	new->prev = NULL;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else if (mod == 1)
	{
		while (last->prev != NULL)
			last = last->prev;
		last->prev = new;
		new->next = last;
	}
	else
	{
		new->prev = *stack;
		(*stack)->next = new;
		*stack = new;
	}
	free(opcode);
	free(arg);
}

/**
 * perform_other_op - performs various other op instructions
 * @stk: top of stack
 * @op_c: operation code
 * @oparr: array containing opcodes and associated functions
 * @l_n: line number read from script
 *
 * Return: nothing
 */
void perform_other_op(stack_t **stk, char *op_c, instruction_t **oparr, ssize_t l_n)
{
	int num, found = 0;

	for (num = 0; oparr[num] != NULL; num++)
	{
		if (strcmp(op_c, (oparr[num])->opcode) == 0)
		{
			if (oparr[num]->f != NULL)
				oparr[num]->f(stk, l_n);
			found = 1;
			break;
		}
	}
	if (found == 0)
	{
		fprintf(stderr, "L%lu: unknown instruction %s\n", l_n, op_c);
		free_all_resources(stk, op_c, NULL);
		exit(EXIT_FAILURE);
	}
	free(op_c);
}

/**
 * set_execution_mode - change the mode to queue or stack
 * @opcode: operation code to change mode
 *
 * Return: 0 for stack and 1 for queue
 */
ssize_t set_execution_mode(char *opcode)
{
	ssize_t mode;

	if (strcmp(opcode, "stack") == 0)
		mode = 0;
	else
		mode = 1;
	free(opcode);
	return (mode);
}

/**
 * main - main monty function
 * @argc: arg count
 * @argv: arg vector
 *
 * Return: 0 if succesful
 */
int main(int argc, char **argv)
{
	FILE *script;
	ssize_t line_number = 1, check, mode = 0;
	stack_t *stack = NULL;
	char *buffer, *op = NULL, *arg = NULL;

	if (argc != 2)
		print_usage_error();
	script = fopen(argv[1], "r");
	if (script == NULL)
		print_file_error(argv[1]);
	create_operation_list();
	buffer = malloc(256 * sizeof(char));
	if (buffer == NULL)
		print_malloc_error();
	while ((fgets(buffer, 256, script)) != NULL)
	{
		check = tokenize_input_line(buffer, &op, &arg);
		if (check == 1)
			continue;
		else if (check == -1)
		{
			free_all_resources(&stack, NULL, NULL);
			print_malloc_error();
		}
		if ((strcmp(op, "stack") == 0) || (strcmp(op, "queue") == 0))
			mode = set_execution_mode(op);
		else if (strcmp(op, "push") == 0)
			perform_push(&stack, arg, line_number, op, mode);
		else
			perform_other_op(&stack, op, operation_list, line_number);
		line_number++;
	}
	fclose(script);
	free(buffer);
	free_all_resources(&stack, NULL, NULL);
	exit(EXIT_SUCCESS);
}
