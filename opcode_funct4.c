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
