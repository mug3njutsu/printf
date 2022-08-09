#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
*print_rev - prints a str in reverse
*@r: str to print
*Return: n chars printed
*/

int print_rev(va_list r)
{
	char *st;
	int i, j = 0;

	st = va_arg(r, char *);
	if (st == NULL)
		st = ")llun(";
	for (i = 0; st[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}
