#include "monty.h"

/**
 * free_stack_memory - frees a dlistint_t list.
 * @rear: rear of doubly linked list.
 */
void free_stack_memory(stack_t *rear)
{
	stack_t *temp;

	while (rear != NULL)
	{
		temp = rear;
		rear = rear->prev;
		free(temp);
	}
}
