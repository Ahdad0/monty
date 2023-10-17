#include "monty.h"

void check(char *arg, stack_t **stack)
{
	if (strcmp(arg, "push") == 0)
	{
		line++;
		push(stack, line);
	}
	else if (strcmp(arg, "pall") == 0)
	{
		line++;
		pall(stack, line);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, arg);
		exit(EXIT_FAILURE);
	}
}
