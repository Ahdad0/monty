#include "monty.h"

int v;
unsigned int line = 1;

void check(char **arg, stack_t **stack)
{
	stack_t *current;
	int i;

	if (strcmp(arg[0], "push") == 0)
	{
		push(stack, arg[1], line);
		for (i = 0; arg[i]; i++)
		{
			free(arg[i]);
		}
		free(arg);
		line++;
	}
	else if (strcmp(arg[0], "pall") == 0)
	{
		pall(stack);
		for (i = 0; arg[i]; i++)
		{
			free(arg[i]);
		}
		free(arg);

		while (*stack != NULL)
		{
			current = *stack;
			*stack = (*stack)->next;
			free(current);
		}

		line++;
	}
	else 
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, arg[0]);
		for (i = 0; arg[i]; i++)
		{
			free(arg[i]);
		}
		free(arg);
		exit(EXIT_FAILURE);
	}
}
