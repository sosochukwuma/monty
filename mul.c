#include "monty.h"

/**
 * _mul - ldfñal,dñal,sdñal,sñla,
 * @stack: sñdlf,ñld,cñsl,d
 * @line_number: dmfalm,ñl,scal,
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack && (*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n *= (*stack)->n;
		temp = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(temp);
	}
}
