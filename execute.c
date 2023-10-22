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
 * swap - swap two value from top
 *
 * @stack: head of the node
 * @line: line of number
 */
void swap(stack_t **stack, unsigned int line)
{
	stack_t *curr = *stack, *last;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}


	if (curr != NULL && curr->next != NULL)
	{
		last = curr->next;

		if (last->next != NULL)
		{
			last->next->prev = curr;
		}

		curr->next = last->next;
		last->prev = NULL;
		last->next = curr;
		curr->prev = last;

		*stack = last;
	}
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: head of the node
 * @line: line number
 */
void pop(stack_t **stack, unsigned int line)
{
	stack_t *curr = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	curr = *stack;

	if (curr != NULL)
	{
		*stack = curr->next;
		free(curr);
	}
}

/**
 * pint - print value at top of stack
 *
 * @stack: head of the node
 * @line: line number
 */
void pint(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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
