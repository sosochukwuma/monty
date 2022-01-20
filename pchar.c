#include "monty.h"

/**
 * _pchar - ñslkdfñd,ñsl,d
 * @stack: ñldfñld,fñsld,f
 * @line_number: ñlsdf{sldf,ñsd,lf
 */
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pchar, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	else if ((*stack)->n < 32 || (*stack)->n > 127)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pchar, value out of range\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}

	else
	{
		printf("%c\n", (*stack)->n);
	}
}
