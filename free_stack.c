#include "monty.h"

void free_stack(stack_t *stack)
{
    stack_t *freeing;
    freeing = stack;
    while (stack != NULL)
    {
        freeing = stack->next;
        free(stack);
        stack = freeing;
    }
}
