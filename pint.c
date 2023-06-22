#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the head node of the stack
 * @line_number: current line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	printf("%d\n", (*stack)->n);
}
