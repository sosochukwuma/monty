#include "monty.h"

global_t global = {NULL, 0};

/**
 * main - dfjñadfmñd
 * @argc: slkdfñsdkfñskdlf
 * @argv: sñdkfñlskdfñslkd
 * Return: akfañkdfñkdfñlka
 */
int main(int argc, char **argv)
{
	char buf[1024], t[128] = "", *token = t;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.fp = fopen(argv[1], "r");
	if (!(global.fp))
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n",
			argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buf, sizeof(buf), global.fp))
	{
		token = strtok(buf, " \t");
		if (token[0] == '#')
			_nop(&stack, line_number);
		else if (token[0] != '\n')
			_get_(&stack, token, line_number)(&stack,
				   line_number);
		line_number++;
	}
	free_all(&stack);
	return (EXIT_SUCCESS);
}
