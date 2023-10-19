#include "monty.h"

void process(stack_t **stack, unsigned int line_number, char *data)
{
    int i;
    char *command = NULL;
    instruction_t codes[] = {
        {"push", push}, {"pall", pall}, {NULL, NULL}
    };
    
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
}
