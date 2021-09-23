#include "monty.h"

/**
 * check_status - Checks if function executed properly.
 * @prev_tok_len: Previous lenght of op_toks.
 *
 * Return: exit status.
 */
int check_status(int prev_tok_len)
{
	int exit_status;

	if (op_toks && op_toks[prev_tok_len])
		exit_status = atoi(op_toks[prev_tok_len]);
	else
		exit_status = EXIT_FAILURE;
	free_tokens();

	return (exit_status);
}
