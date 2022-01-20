#include "monty.h"

/**
 * _mod - dmfñlsd,ñsl,dñls,d
 * @stack: ñdlfpñdf,sñd,l
 * @line_number: sdlñ,sñd,sñl,d
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't mod, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: division by zero\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
