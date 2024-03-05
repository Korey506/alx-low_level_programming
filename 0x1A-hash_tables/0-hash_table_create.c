#include "hash_tables.h"

/**
 * hash_table_create - this function creates a hash table
 * @size: the size of the array
 * Return: the created table is returned on success
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ntable = NULL;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ntable = malloc(sizeof(hash_table_t));
	if (ntable == NULL)
		return (NULL);

	ntable->array = malloc(sizeof(hash_node_t *) * size);
	if (ntable->array == NULL)
	{
		free(ntable);
		return (NULL);
	}

	ntable->size = size;
	for (i = 0; i < size; i++)
		ntable->array[i] = NULL;

	return (ntable);
}
