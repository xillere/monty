#include "monty.h"
#include <stdio.h>
#include <unistd.h>


fileinfo_t info;
void process(stack_t **stack);

/**
 * main - monty program
 * @argc: args
 * @argv: argv
 * Return: integers
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *op;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op = fopen(argv[1], "r");
	info.file = op;
	if (info.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process(&stack);

	free_stack(stack);
	fclose(op);
	return (0);
}
