#include "monty.h"
/**
 * pint - prints from the top of the stack
 * @stack: stack
 * @line_number: line no.
 * Return: non
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(info.file);
		free(info.fileline);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
