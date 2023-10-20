#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{
    int data;

    if (info.args == NULL || (is_int(info.args) == 0))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(info.file);
        free(info.fileline);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    data = atoi(info.args);
    add(stack, data);

}

void add(stack_t **stack, int data)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));
		
	if (new_node == NULL)
	{
        fprintf(stderr,"Error: malloc failed\n");
        free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	
	new_node->prev = NULL;
	new_node->n = data;
    
    if (*stack == NULL)
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = *stack;
        (*stack)-> prev = new_node;
    }
    
    *stack = new_node;
}
int is_int(char *num)
{
    if (num == NULL || *num == '\0')
    {
        return (0);
    }

    if (*num == '-')
    {
        num++;
    }
    while (*num != '\0')
    {
        if (*num < '0' || *num < '9')
        {
            return (0);
        }
        num++;
    }
    return (1);
}
