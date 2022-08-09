#include "main.h"

unsigned int convert_x(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_X(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_x - converts an unsigned int arg to hex.
 * @args: a va_list -> arg to be converted.
 * @flags: flag modifiers.
 * @wid: a width modifier.
 * @prec: a precision modifier.
 * @len: a length modifier.
 * @output: a buffer_t struct containing char[].
 * Return: n bytes stored to the buffer.
 */

unsigned int convert_x(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x";

	if (len == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789abcdef", flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}

/**
 * convert_X - converts an unsigned int argument to hex.
 * @args: a va_list -> arg to be converted.
 * @flags: flag modifiers.
 * @wid: a width modifier.
 * @prec: a precision modifier.
 * @len: a length modifier.
 * @output: a buffer_t struct containing char[].
 * Return: n bytes stored to the buffer.
 */

unsigned int convert_X(va_list args, buffer_t *output,
unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (len == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && prec == 0))
		ret += convert_ubase(output, num, "0123456789ABCDEF", flags, wid, prec);

	ret += print_neg_width(output, ret, flags, wid);

	return (ret);
}
