#include "monty.h"

void handle(char *s, stack_t **stack)
{
	char *tok, **arr;
	int i = 0;

	arr = malloc(sizeof(char *) * 3);

	tok = strtok(s, " \n\t");

	while (tok != NULL)
	{
		arr[i] = my_strdup(tok);

		if (arr[i] == NULL)
		{
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}

		tok = strtok(NULL, " \n\t");
		i++;
	}

	arr[i] = NULL;

	check(arr, stack);
}
char *my_strdup(const char *str)
{
	char *new_str;
	size_t len = strlen(str);

	if (str == NULL) {
		return NULL;
	}

	new_str = (char *)malloc(len + 1);
	if (new_str == NULL) {
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(new_str, str);

	return new_str;
}
