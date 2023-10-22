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
void push(stack_t **stack, char *s[], unsigned int line)
{
	stack_t *node;
	int che;
	char num;

	che = strlen(s[1]);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (che <= 1)
		num = s[1][0];
	else if (che > 1)
		num = s[1][1];

	if (s == NULL || isdigit(num) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		free_s(s);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		node->n = atoi(s[1]);
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
