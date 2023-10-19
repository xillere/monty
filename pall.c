#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *display = *stack;

    while (display != NULL)
    {
        printf("%d\n", display->n);
        display = display->next;
        (void)line_number; 
    }
}
