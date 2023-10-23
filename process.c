#include "monty.h"

/**
 * process - do
 * @stack: stack
 * Return: no
 */

void process(stack_t **stack)
{
	int i;
	size_t len = 0;
	ssize_t nread;
	int line_number = 0;
	char *command = NULL;
	instruction_t codes[] = {
		{"push", push}, {"pall", pall}, {"pop", pop}, {"add", addf},
		{"nop", nop}, {"pint", pint}, {"swap", swap}, {NULL, NULL}
	};

	while ((nread = getline(&info.fileline, &len, info.file)) != -1)
	{
		line_number++;
		command = strtok(info.fileline, " \n\t");
		info.args = strtok(NULL, " \n\t");
		for (i = 0; codes[i].opcode != NULL; i++)
		{
			if (strcmp(command, codes[i].opcode) == 0)
			{
				codes[i].f(stack, line_number);
				break;
			}
		}
		if (command && codes[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
}
