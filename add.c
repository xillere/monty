#include "monty.h"
/**
 * addf - adds last two elements in the stack
 * @stack: pointer to the stack
 * @line_number: line no.
 **/
void addf(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(info.fileline);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
