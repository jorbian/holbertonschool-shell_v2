#include "include/arrays.h"

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

/**
 * search_array - searches a string array for strings which match terms
 * @length: number of items it contains
 * @array: an array of strings to be looked at
 * @terms: function pointer to criteria being used
 *
 * Return: Double pointer to a new array containing matches
*/
char **search_array(size_t length, char **array, int (*terms)(const char *))
{
	char **matches;

	size_t i = 0;
	size_t j = 0;

	size_t num_of_hits = get_num_of_matches(
		length, array, terms
	);
	if (num_of_hits <= 0)
		return (NULL);

	matches = new_string_array(num_of_hits + 1);
	if (matches == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		if (terms(array[i]))
		{
			matches[j] = _strdup(array[i]);
			j++;
		}
	}
	matches[num_of_hits] = NULL;

	return (matches);
}

/**
 * get_num_of_matches - how many matches an array will have
 * @length: number of items it contains
 * @array: an array of strings to be looked at
 * @terms: function pointer to criteria being used
 *
 * Return: How many indecies the new array must have
*/
size_t get_num_of_matches(size_t length, char **array, int (*terms)(const char *))
{
	size_t i = 0;
	size_t matches = 0;

	for (i = 0; i < length; i++)
	{
		if (terms(array[i]))
			matches++;
	}
	return (matches);
}
