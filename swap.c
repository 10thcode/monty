#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: a pointer to the head of the stack
 * @line_number: the current line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
