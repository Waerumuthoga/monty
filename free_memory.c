#include "monty.h"
/**
 * free_memory - frees memory in the stack
 * @stack: stack or queue
 * Return: void
 */
void free_memory(stack_t **stack)
{
	stack_t *present = *stack;
	stack_t *temp;

	if (!stack || !(*stack))
	{
		return;
	}
	while (present != NULL)
	{
		temp = present->next;
		free(present);
		present = temp;
	}
}
