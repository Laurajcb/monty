#include "monty.h"

/**
 * _push -Push a new element in the stack
 * @stack:Double pointer to the head of the Stack.
 * @line_number: line number or the command
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL, *tmp = NULL;
	unsigned int i = 0;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		set_op_tok_error(malloc_error());
		return (NULL);
	}
	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}
	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new_node->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		_pushmode(0, stack, new_node);
	}
	else
	{
		_pushmode(1, stack, new_node);
	}
}

/**
 * _pall -Print the elements in a stack
 * @stack: Double pointer to the head of the Stack.
 * @line_number: line number or the command
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *list = *stack;
	(void)line_number;

	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
	}
}
/**
 * _pint -Get the value of the top of the stack
 * @stack: Double pointer to the head of the Stack.
 * @line_number:line number of the command
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->n);
}
/**
 * _pop -Function removes the top element of the stack.
 * @stack:Double pointer to the head of the Stack.
 * @line_number: line number.
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);

	if (next)
	{
		next->prev = *stack;
	}
	(*stack)->next = next;
}

/**
 * _swap -Function swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: line number.
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int trade;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	trade = (*stack)->next->next->n;

	(*stack)->next->next->n = (*stack)->next->n;
	(*stack)->next->n = trade;
}
