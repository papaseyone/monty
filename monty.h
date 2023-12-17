#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t **operation_list;
instruction_t **operation_list;
void create_operation_list(void);
void print_stack_content(stack_t **stack, unsigned int line_number);
void free_stack_memory(stack_t *rear);
void free_all_resources(stack_t **stack, char *opcode, char *arg);
void pop_stack_top(stack_t **stack, unsigned int line_number);
int tokenize_input_line(char *buf, char **opcode, char **arg);
void add_instruction(instruction_t **d, char *oc, void (*f)(stack_t**, unsigned int));
void free_instructions(void);
void print_file_error(char *file);
void print_usage_error(void);
void print_malloc_error(void);
void print_top_stack_element(stack_t **stack, unsigned int line_number);
void swap_top_two_elements(stack_t **stack, unsigned int line_number);
void add_top_two_elements(stack_t **stack, unsigned int line_number);
void subtract_top_two_elements(stack_t **stack, unsigned int line_number);
void multiply_top_two_elements(stack_t **stack, unsigned int line_number);
void divide_top_two_elements(stack_t **stack, unsigned int line_number);
void modulo_top_two_elements(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotate_right(stack_t **stack, unsigned int line_number);
void rotate_left(stack_t **stack, unsigned int line_number);
void check_arguments(stack_t **stack, unsigned int line_number, char *op, char *arg);

#endif
