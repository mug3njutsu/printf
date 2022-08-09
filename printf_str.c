#include "main.h"

/**
 * _strlen - Returns the len(str)
 * @s: Type char *p
 * Return: c.
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);

}

/**
 * _strlenc - strlen func
 * @s: Type char *p
 * Return: c
 */

int _strlenc(const char *s)
{
	int c;

	for (c = 0; s[c] != 0; c++)
		;
	return (c);
}
