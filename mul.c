#include "monty.h"

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: a pointer to the head node of the stack
 * @line_number: the current line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
