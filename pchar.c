#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: a pointer to the head node of the stack
 * @line_number: the current line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	printf("%c\n", (*stack)->n);
}
