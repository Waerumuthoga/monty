#include "monty.h"

/**
 * push - inputs data to the stack (or queue)
 * @stack: pointer to the head
 * @line_number: line number
 * Return: nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	int data;
	stack_t *new_node;
	char *arg = strtok(NULL, " \t\n");

	if (!arg || !isdigit(arg[0]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	data = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = data;
	new_node->prev = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	} else
	{
		new_node->next = NULL;
	}
	*stack = new_node;
}
/**
 * pall - prints whats in the stack or que
 * @stack: pointer to the head
 * @line_number: line number
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
