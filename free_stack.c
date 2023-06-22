#include "monty.h"

/**
 * free_stack - free all nodes in stack
 * @stack: head node of the stack
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;

	if (stack->next == NULL)
	{
		free(stack);
		return;
	}

	free_stack(stack->next);
	free(stack);
}
