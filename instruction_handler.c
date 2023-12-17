#include "monty.h"

/**
 * add_instruction - creates a instruction data
 * @d: allocated memory for data
 * @oc: opcode for the instruction
 * @f: function for particular opcode
 */
void add_instruction(instruction_t **d, char *oc, void (*f)(stack_t **, unsigned int))
{
	char *opcode;
	void (*func)(stack_t **, unsigned int) = f;
	instruction_t *new;

	opcode = malloc((strlen(oc) + 1) * sizeof(char));
	if (opcode == NULL)
		print_malloc_error();
	strcpy(opcode, oc);
	new = malloc(sizeof(instruction_t));
	*d = new;
	(*d)->opcode = opcode;
	(*d)->f = func;
}

/**
 * free_instructions - frees array of instruction data type
 */
void free_instructions(void)
{
	int x;

	for (x = 0; operation_list[x] != NULL; x++)
	{
		free((operation_list[x])->opcode);
		free(operation_list[x]);
	}
	free(operation_list);
}

/**
 * create_operation_list - creates an array of instruction_t data for opcodes
 *
 * Return: return a pointer to an array of instructions with matcged opcodes
 */
void create_operation_list(void)
{
	operation_list = malloc(15 * sizeof(instruction_t *));

	if (operation_list == NULL)
		print_malloc_error();
	add_instruction(&operation_list[0], "pall", &print_stack_content);
	add_instruction(&operation_list[1], "pop", &pop_stack_top);
	add_instruction(&operation_list[2], "pint", &print_top_stack_element);
	add_instruction(&operation_list[3], "swap", &swap_top_two_elements);
	add_instruction(&operation_list[4], "add", &add_top_two_elements);
	add_instruction(&operation_list[5], "sub", &subtract_top_two_elements);
	add_instruction(&operation_list[6], "mul", &multiply_top_two_elements);
	add_instruction(&operation_list[7], "div", &divide_top_two_elements);
	add_instruction(&operation_list[8], "mod", &modulo_top_two_elements);
	add_instruction(&operation_list[9], "print_char", &print_char);
	add_instruction(&operation_list[10], "print_string", &print_string);
	add_instruction(&operation_list[11], "rotate_right", &rotate_right);
	add_instruction(&operation_list[12], "rotate_left", &rotate_left);
	add_instruction(&operation_list[13], "nop", NULL);
	operation_list[14] = NULL;
}
