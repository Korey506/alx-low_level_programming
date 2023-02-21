#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *a = "main";

	while (*a)
	{
		_putchar(*a);
		a++;
	}
	_putchar('\n');

	return (0);
}
