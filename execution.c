#include "monty.h"
/**
 * execute_commands - runs opcode instructions
 * @file: path to the file containing Monty byte code
 * Return: nothing
 */
void execute_commands(FILE *file)
{
	stack_t *stack = NULL;
	char *opcode, buffer[1024];
	int line_number;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
	};
	size_t n;

	while (fgets(buffer, sizeof(buffer), file))
	{
		opcode = strtok(buffer, "\t\n");
		if (!opcode)
		{
			line_number++;
			continue;
		}
		for (n = 0; n < sizeof(instructions) / sizeof(instructions[0]);
				n++)
			if (strcmp(opcode, instructions[n].opcode) == 0)
			{
				instructions[n].f(&stack, 0);
				break;
			}
	}
	free_memory(&stack);
}
