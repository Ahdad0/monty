#include "monty.h"

static unsigned int line = 1;
int v;

void handle(char *s, stack_t **stack)
{
	char *tok, **arr;
	int i = 0;

	arr = malloc(sizeof(char *) * 3);

	tok = strtok(s, " \n\t");

	while (tok != NULL)
	{
		arr[i] = strdup(tok);
		tok = strtok(NULL, " \n\t");
		i++;
	}

	arr[i] = NULL;

	if (arr[1] != NULL)
		v = atoi(arr[1]);

	check(arr[0], stack);
}
