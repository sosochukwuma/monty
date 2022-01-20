#include "monty.h"

/**
 * _pall - ldlflclsp
 * @stack: llsdlksdlfkñldf
 * @line_number: ñlkdfñalkñalñla
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *pp = *stack;
	(void) line_number;

	while (pp)
	{
		printf("%d\n", pp->n);
		pp = pp->next;
	}
}
