#include "monty.h"

/**
 * handle - separate argument
 *
 * @s: string
 * @stack: head of the node
 */
void handle(char *s, stack_t **stack)
{
	char *tok, **arr;
	int i = 0, j;

	arr = malloc(sizeof(char *) * 3);

	tok = strtok(s, " \n\t");

	while (tok != NULL)
	{
		arr[i] = my_strdup(tok);

		if (arr[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(arr[j]);
			}
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}

		tok = strtok(NULL, " \n\t");
		i++;
		if (i == 2)
		{
			break;
		}
	}

	arr[i] = NULL;

	check(arr, stack);
}

/**
 * my_strdup - duplicate a string
 *
 * @str: string
 *
 * Return: new string
 */
char *my_strdup(const char *str)
{
	char *new_str;
	size_t len;

	len = strlen(str);

	if (str == NULL)
	{
		return (NULL);
	}

	new_str = malloc(len + 1);

	if (new_str == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	strcpy(new_str, str);

	return (new_str);
}
