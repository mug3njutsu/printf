#include "main.h"

/**
 * _puts - prints a string
 * @string: input str
 * Return: stuff
 */

int _puts(char *string)
{
	int contador = 0;

	while (*string)
	{
		_putchar(*string);
		string++;
		contador++;
	}
	return (contador);
}
