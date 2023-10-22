#include "monty.h"

/**
 * pall - prints all the values pushed to the stack
 * @stack: stack
 * @line_number: number no.
 */

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
