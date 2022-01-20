#include "monty.h"

/**
 * _add - sñdlkfpsd,cñsl,d
 * @stack: sdlkñfañld,
 * @line_number: djkfposdkps
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack && (*stack)->next)
	{
		(*stack)->next->n += (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{

		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
