#include "main.h"

/**
 * printc - prints char
 * @pa: format of char
 * @format: format
 * Return: int
 */

int printc(char *format, va_list pa)
{
	(void)format;
	_putchar(va_arg(pa, int));
	return (1);
}
