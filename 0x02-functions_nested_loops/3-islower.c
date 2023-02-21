#include "main.h"

/*
 * _islower - Entry point
 *
 * Description: A function that checks for lowwercase character
 *
 * Return: Always 0 (Success)
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z') 
	{
	return 1;
	
	}

	else
	{
	return 0;
	}


	int result = _islower('a');
	
	if (result)
	{
	putchar('1');
	}	
	else 
	{
    putchar('0');
	}
}
