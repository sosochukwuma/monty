#include "monty.h"

/**
 * _push - d{lñf,,d,c.ñlñ{sdñsñs
 * @stack: ldñdñdlñdñfld
 * @line_number: sdpflxcldldñcñx
 */
void _push(stack_t **stack, unsigned int line_number)
{
	char arg[128] = "", *arg_p = arg;
	int argument;
	unsigned int i;

	arg_p = strtok(NULL, " \t");
	if (arg_p)
	{
		if (arg_p[0] == '\n')
			push_error(stack, line_number);
		for (i = 0; i < strlen(arg_p); i++)
		{
			if (!isdigit(arg_p[i]) && arg_p[0] != '-' &&
			    arg_p[i] != '\n')
				push_error(stack, line_number);
		}
		argument = atoi(arg_p);
	}
	else
		push_error(stack, line_number);

	if (global.queue)
		add_node_end(stack, argument);
	else
		add_node(stack, argument);
}

/**
 * push_error - ñlkfsñdlf,sñdf,
 * @stack: sdlf,ñlsdfñs,d
 * @line_number: sñdlfñlsd,fsñld,f
 */
void push_error(stack_t **stack, unsigned int line_number)
{
	dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
		line_number);
	free_all(stack);
	exit(EXIT_FAILURE);
}

/**
 * add_node - ñsdlfksñdlfkñsd,fñlsd,f
 * @stack: skdlsdfñ,sdñlf,d
 * @argument: dñslfsdñkflsñdlf,
 */
void add_node(stack_t **stack, int argument)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	new->n = argument;
	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * add_node_end - kfañkdadkñadmklamdf
 * @stack: ñlsdkfñsdkfñskdlf
 * @argument: sldñkfsñldkfñslkdf
 */
void add_node_end(stack_t **stack, int argument)
{
	stack_t *last = *stack;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	new->n = argument;
	new->next = NULL;

	if (*stack == NULL)
	{
		new->prev = NULL;
		*stack = new;
		return;
	}

	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}
