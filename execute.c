#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fprintf(stderr, "Error: malloc failed");

	node->n = v;
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
