#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: a pointer to the head node of the stack
 * @line_number: the current line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->n < 1 || (*stack)->n > 127)
	{
		printf("\n");
		return;
	}

	printf("%c", (*stack)->n);
	pstr(&(*stack)->next, line_number);
}
