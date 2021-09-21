#include "monty.h"
/**
 * push - push a new element in the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void push(stack_t **stack, unsigned int line_number)
{
}

/**
 * pall - print the elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *aux_stack = *stack;

    global->line_n = line_number;

    while (aux_stack != NULL)
    {
        printf("%d\n", aux_stack->n);
        aux_stack = aux_stack->next;
    }
}
/**
 * pint - get the value of the top of the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pint(stack_t **stack, unsigned int line_number)
{
    global->line_n = line_number;
    global->stack = *stack;

    if ((*stack) == NULL)
        exit();
    printf("%d\n", (*stack)->n);
}
