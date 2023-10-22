#include "monty.h"
/**
 * pop - removes the last in element of stack
 * @stack: the stack
 * @line_number: line no
 **/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *del;

	if (*stack == NULL)
	{
		free(info.fileline);
		free_stack(*stack);
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	del = *stack
	*stack = del->next;
	free(*del);
}
