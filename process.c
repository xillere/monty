#include "monty.h"

void process(stack_t **stack)
{
    int i, bool = 0;
    size_t len = 0;
    ssize_t nread;
    unsigned int line_number;
    char *command = NULL;
    
    instruction_t codes[] = {
        {"push", push}, {"pall", pall}, {"pop",pop},
	{"pint", pint}, {NULL, NULL}
    };
    while((nread = getline(&info.fileline, &len, info.file)) != -1)
    {
	    line_number++;
    command = strtok(info.fileline, " \n\t");
    info.args = strtok(NULL, " \n\t");

    for (i = 0; codes[i].opcode != NULL; i++)
    {
        if (strcmp(command, codes[i].opcode) == 0)
        {
            codes[i].f(stack, line_number);
        }

    }
    }
	/*fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);*/
    /*free_stack(*stack);*/
    exit(EXIT_FAILURE);
}
