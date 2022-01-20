#include "monty.h"

/**
 * _swap - ñlfkñlsdkfñdklfñlkdfñlkd
 * @stack: ñskdfñldkfñlkdlñ
 * @line_number: d´fk{sd{fkls{dkf{skdl
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}

	else
	{
		dprintf(STDERR_FILENO,
			"L%u: can't swap, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
