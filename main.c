#include "monty.h"
/**
 * main - program function that takes in command line arguments
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
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
	execute_commands(file);

	fclose(file);

	return (EXIT_SUCCESS);
}
