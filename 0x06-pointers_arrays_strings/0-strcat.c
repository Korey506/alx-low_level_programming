#include "main.h"
#include <string.h>

/**
 * _strcat - concatenates two strings dest and src.
 * @dest: destination array to concat.
 * @src: source array to concat.
 * Return: Always dest.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest + strlen(dest);

	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (dest);
}
