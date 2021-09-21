#include "monty.h"

/**
 * _mod -Function mudule to the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Line number.
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}
	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	result = (*stack)->next->next->n % (*stack)->next->n;

	(*stack)->next->next->n = result;
	_pop(stack, line_number);
}

/**
 * _pchar-Prints the char at the top of the stack,
 * @stack: Double pointer to the head of the Stack.
 * @line_number: line number.
 */

void _pchar(stack_t **stack, unsigned int line_number)
{

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
									 "value out of range"));
		return;
	}
	printf("%c\n", (*stack)->next->n);
}

/**
 * _pstr -prints the string starting at the top of the stack
 * @stack:Double pointer to the head of the Stack.
 * @line_number:line number.
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *list = (*stack)->next;
	(void)line_number;

	while (list)
	{
		if (list->n == 0 && list->n <= 126)
			printf("%c", list->n);

		list = list->next;
	}
	printf("\n");
}

/**
 * _rotl -Rotates the stack to the top.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: line number.
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *list, *end;
	(void)line_number;

	list = end = (*stack)->next;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;
	while (end->next)
		end = end->next;

	list->next->prev = (*stack);
	(*stack)->next = list->next;
	end->next = list;
	list->next = NULL;
	list->prev = end;
}

/**
 * _rotr -Rotates the stack to the bottom.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: line number.
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *end, *head = (*stack)->next;
	(void)line_number;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	end = (*stack)->next;
	while (end->next != NULL)
		end = end->next;

	end->prev->next = NULL;
	(*stack)->next = end;
	end->prev = *stack;
	end->next = head;
	head->prev = end;
}
