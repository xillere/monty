#include "monty.h"
#include <stdio.h>
#include <unistd.h>

fileinfo_t info;
void process(stack_t **stack, unsigned int line_number, char *data);


int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_no = 0;
	stack_t *stack = NULL;
	ssize_t nread;
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

	while ((nread = getline(&line, &len, info.file)) != -1)
	{
		info.fileline = line;
		line++;
		process(&stack, line_no, line); 
		
	}
	free(info.fileline);
	free_stack(stack);
	fclose(op);
	return (0);
}
