#include "monty.h"

/**
* main - main function
* @argc: number of argument
* @argv: argument
*
* Return: to 0
*/

int main(int argc, char *argv[])
{
	FILE *file;
	char *lineptr, *command, *command2;
	size_t n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, file) != -1)
	{
		command = strtok(lineptr, " ");
		mon_s.arg = strtok(NULL, " ");
		printf("%s %s\n", command, mon_s.arg);
	}
	return (0);
}
