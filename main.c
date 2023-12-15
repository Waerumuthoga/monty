#include "monty.h"
/**
 * main - program function that takes in command line arguments
 * @argc: number of arguments passed to the program
 * @argv: array of strings containing the arguments
 * Return: int
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");

	if (argc != 2 || file == NULL)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
	}

	execute_commands(file);

	fclose(file);
	return (EXIT_SUCCESS);
}
