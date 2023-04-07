#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: If b is NULL or contains chars not 0 or 1 - 0.
 *         Otherwise - the converted number.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int x, y;
	int base_two;

	if (!b)
		return (0);

	for (base_two = 0; b[base_two]; base_two++)
		;
	base_two--;
	for (y = 1, x = 0; base_two >= 0; base_two--)
	{
		if (b[base_two] == '0')
		{
			y *= 2;
			continue;
		}
		else if (b[base_two] == '1')
		{
			x += y;
			y *= 2;
			continue;
		}
		return (0);
	}
	return (x);
}
