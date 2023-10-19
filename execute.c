#include "monty.h"

void pall(stack_t **stack)
{
	stack_t *curr = *stack;
	
	if (curr != NULL)
	{
		while (curr != NULL)
		{
			printf("%d\n", curr->n);
			curr = curr->next;
		}
	}
}

void push(stack_t **stack, char *s, unsigned int line)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (s == NULL || isdigit(s[0]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	else
	{
		node->n = atoi(s);
	}
	node->prev = NULL;

	if (*stack != NULL)
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	else
		node->next = NULL;

	*stack = node;
}
