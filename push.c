#include "monty.h"


void push(stack_t **stack, unsigned int line_number)
{
    int data;

    if (info.args == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    data = atoi(info.args);
    add(stack, data);
    (void)line_number;


}

void add(stack_t **stack, int data)
{
	stack_t *new_node;
	new_node = malloc(sizeof(stack_t));
		
	if (new_node == NULL)
	{
        fprintf(stderr,"Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->prev = NULL;
	new_node->n = data;
	new_node->next = *stack;
    
    if (*stack != NULL)
    {
        (*stack)-> prev = new_node;
    }
    
    *stack = new_node;
}
