#include "monty.h"

/**
 * free_s - free string
 *
 * @s: string
 */
void free_s(char **s)
{
	int i = 0;

	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

/**
 * free_stack - free node
 *
 * @stack: head of node
 */
void free_stack(stack_t **stack)
{
	stack_t *curr;

	while (*stack != NULL)
	{
		curr = *stack;
		*stack = (*stack)->next;
		free(curr);
	}
}
