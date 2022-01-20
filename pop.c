#include "monty.h"

/**
 * _pop - lñdf,ña,cñalsd,cñla,d
 * @stack: ñdlfñl,cñl,dc
 * @line_number: dlkf,sñd,lsp,d
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		if ((*stack)->next)
			(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		free(temp);
	}

	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
