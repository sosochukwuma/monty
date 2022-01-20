#include "monty.h"

/**
 * _rotl - sl´spdl´lpdc´plsd
 * @stack: sñdlksñld,fñls,d
 * @line_number: dfkñdlkfsñkdlfñlskdlf
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;

	if (*stack && (*stack)->next)
	{
		while (curr->next)
			curr = curr->next;
		curr->next = *stack;
		(*stack)->prev = curr;
		*stack = (*stack)->next;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
}
