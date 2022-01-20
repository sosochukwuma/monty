#include "monty.h"

/**
 * _pint - añlkd,dñla,dao,sd
 * @stack: lñd,apd,ñal,s
 * @line_number: kaopd,aps,capos,
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
}
