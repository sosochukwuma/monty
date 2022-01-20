#include "monty.h"

/**
 * _rotr - ñdlkfñldkfñkdfñlk
 * @stack: adlkalñdkfñakdfl
 * @line_number: dfkañdkfñlkdflkdfñ
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	(void) line_number;

	if (*stack && (*stack)->next != NULL)
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = *stack;
		(*stack)->prev = curr;
		curr->prev->next = NULL;
		curr->prev = NULL;
		*stack = curr;
	}
}
