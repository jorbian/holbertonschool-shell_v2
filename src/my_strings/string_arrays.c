#include "my_strings.h"

/**
 * new_string_array - allocates a place in memory for array of x length
 * @length: however long the array needs to be
 *
 * Return: Double pointer to first index
*/
char **new_string_array(size_t length)
{
	char **new_array;

	new_array = malloc((length + 1) * sizeof(char *));
	if (new_array == NULL)
		return (NULL);

	new_array[length] = NULL;

	return (new_array);
}

/**
 * free_string_array - deallocates a string array from memory
 * @array: the array that's no longer needed
*/
void free_string_array(char **array)
{
	size_t i = 0;

	if (array == NULL)
		return;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

/**
 * list_string_array - deallocates a string array from memory
 * @array: array to be looked at
*/
void list_string_array(char **array)
{
	size_t i = 0;

	if (array == NULL)
		return;

	while (array[i])
	{
		printf("INDEX[%ld]: %s\n", i, array[i]);
		i++;
	}
}
