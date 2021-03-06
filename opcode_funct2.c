#include "monty.h"

/**
 * _add -Function adds to the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Line number.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _nop -Function nop doesn’t do anything.
 * @stack:Double pointer to the head of the Stack.
 * @line_number:line number.
 **/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _sub -Function subtraction to the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Line number.
 */

void _sub(stack_t **stack, unsigned int line_number)
{

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}
/**
 * _div -Function divide to the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Line number.
 */

void _div(stack_t **stack, unsigned int line_number)
{

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}
/**
 * _mul -Function multiplies to the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Line number.
 */

void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}
