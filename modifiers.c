#include "main.h"

unsigned int print_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid);
unsigned int print_string_width(buffer_t *output,
unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid);

/**
 * print_width - stores leading spaces to a buffer for a width modifier.
 * @output: a buffer_t struct containing char[].
 * @printed: current numbers of chars.
 * @flags: flag modifiers.
 * @wid: a width modifier.
 * Return: n bytes stored to the buffer.
 */

unsigned int print_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		for (wid -= printed; wid > 0;)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_string_width - Stores leading spaces to a buf for a width modifier.
 * @output: a buffer_t struct containing char[].
 * @flags: flag modifiers.
 * @wid: a width modifier.
 * @prec: a precision modifier.
 * @size: sizeof(str)
 * Return: n bytes stored to the buffer.
 */

unsigned int print_string_width(buffer_t *output,
unsigned char flags, int wid, int prec, int size)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 0)
	{
		wid -= (prec == -1) ? size : prec;
		for (; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}

/**
 * print_neg_width - stores trailing spaces to a buffer for a '-' flag.
 * @output: a buffer_t struct containing char[].
 * @printed: current number of bytes stored.
 * @flags: flag modifiers.
 * @wid: a width modifier.
 * Return: n bytes stored to the buffer.
 */

unsigned int print_neg_width(buffer_t *output, unsigned int printed,
unsigned char flags, int wid)
{
	unsigned int ret = 0;
	char width = ' ';

	if (NEG_FLAG == 1)
	{
		for (wid -= printed; wid > 0; wid--)
			ret += _memcpy(output, &width, 1);
	}

	return (ret);
}
