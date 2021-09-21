#include "monty.h"

/**
 * _pushmode -Push a new element in the stack depent if is stack or queue.
 * @stack: Double pointer to the head of the Stack.
 * @mode: stack or queue.
 * @new_node: new node.
 */
void _pushmode(int mode, stack_t **stack, stack_t *new_node)
{
	stack_t *tmp = NULL;

	if (mode == 0)
	{
		tmp = (*stack)->next;
		new_node->prev = new_node;
		new_node = tmp;

		if (tmp)
			tmp->prev = new_node;
		(*stack)->next = new_node;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new_node->prev = tmp;
		new_node->next = NULL;
		tmp->next = new_node;
	}
}

/**
 * monty_stack - Converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
