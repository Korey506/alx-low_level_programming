 #include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'Z';

	while (letter >= 'a')
	{
		putschar(letter);
		letter--;
	}

	putchar ('\n');

	return (0);
}
