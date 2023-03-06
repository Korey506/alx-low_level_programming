#include <unistd.h>
/**
 * _putchar - write the charater c to stdout
 * @c: The character
 * Return: Wlways 1 9success)
 * on erro, -1 is returned, and error is not appropriate.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
