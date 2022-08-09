#include <unistd.h>
#include "main.h"

/**
 * _putchar - writes the char to stdout
 * @c: char to print
 * Return: On success 1.
 */

int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints a str to stdout
 * @str: *p -> str to print
 * Return: number of chars written
 */

int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
