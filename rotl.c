#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: a pointer to the head node of the stack
 * @line_number: the current line_number
 */
void rotl(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *prev, *next;

	if (*stack == NULL)
		return;

	prev = (*stack)->prev;
	next = (*stack)->next;

	while (next != NULL)
	{
		(*stack)->prev = next;
		(*stack)->next = prev;
		prev = *stack;
		*stack = next;
		next = next->next;
	}

	(*stack)->prev = next;
	(*stack)->next = prev;
}
