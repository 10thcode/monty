#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: a pointer to the head node of the stack
 * @line_number: the current line number
 */
void rotr(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	*stack = tail;
	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
}
