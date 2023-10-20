#include "monty.h"

void process(stack_t **stack, unsigned int line_number, char *data)
{
    int i;
    
    instruction_t codes[] = {
        {"push", push}, {"pall", pall},
	{"pint", pint}, {NULL, NULL}
    };
    char *command;
    
    command = strtok(data, " \n\t");
    info.args = strtok(NULL, " \n\t");

    for (i = 0; codes[i].opcode != NULL; i++)
    {
        if (strcmp(command, codes[i].opcode) == 0)
        {
            codes[i].f(stack, line_number);
            return ;

        }

    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command);
    /*free_stack(*stack);*/
    exit(EXIT_FAILURE);
}
