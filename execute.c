#include "monty.h"

/**
 * pall - print all the node
 *
 * @stack: head of the node
 */
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

/**
 * push - push 's' into the stack
 *
 * @stack: head of node
 * @s: value
 * @line: line number
 */
void push(stack_t **stack, char *s, unsigned int line)
{
	stack_t *node;
	int che;
	char num;

	che = strlen(s);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (che <= 1)
		num = s[0];
	else if (che > 1)
	{
		num = s[1];
	}

	if (s == NULL || isdigit(num) == 0)
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
