#include "monty.h"

/**
 * check - check for the right intruction
 *
 * @arg: arguments
 * @stack: head of node
 */
void check(char **arg, stack_t **stack)
{
	static unsigned int line = 1;

	if (strcmp(arg[0], "push") == 0)
	{
		push(stack, arg[1], line);
		line++;
	}
	else if (strcmp(arg[0], "pall") == 0)
	{
		pall(stack);
		line++;
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, arg[0]);
		exit(EXIT_FAILURE);
	}
}
