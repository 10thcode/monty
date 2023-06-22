#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: a pointer to the head node of the stack
 * @element: the element to be added to @stack
 */
void push(stack_t **stack, unsigned int element)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit_code = EXIT_FAILURE;
		return;
	}

	new_node->n = element;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
