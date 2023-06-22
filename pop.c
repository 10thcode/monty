#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: a pointer to the head node of the stack
 * @line_number: the current line number
 */
void pop(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit_code = EXIT_FAILURE;
		return;
	}

	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
