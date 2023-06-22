#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: a pointer to the head node of the stack
 * @line_number: current line number
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	if (*stack == NULL)
		return;

	printf("%d\n", (*stack)->n);
	pall(&(*stack)->next, line_number);
}
