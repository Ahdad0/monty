#include "monty.h"

int main (int argc, char **argv)
{
	 FILE *file;
	 char line[250];
	 stack_t *stack = NULL;

	 if (argc == 1 || argc > 2)
	 {
		 fprintf(stderr, "USAGE: monty file\n");
		 return (EXIT_FAILURE);
	 }

	 file = fopen(argv[1], "r");

	 if (file == NULL)
	 {
		 fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		 return (EXIT_FAILURE);
	 }

	 while (fgets(line, sizeof(line), file) != NULL)
	 {
		 if (strlen(line) != 1)
			 handle(line, &stack);
	 }

	 fclose(file);

	 return (0);
}
