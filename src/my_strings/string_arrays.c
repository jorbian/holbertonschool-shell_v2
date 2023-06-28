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

/**
 * tokenize_string - used to tokenize a string into an array
 * @string: Contents of this string to be broken broken into tokens.
 * @delimiters: String containing delimiters. May vary one call to another.
 *
 * Return: Newly created array of string seperated into tokens.
*/
char **tokenize_string(char *string, const char *delimiters)
{
	char **ret_array = NULL;
	char *current_token = NULL;

	size_t current_index = 0;
	size_t ret_array_length = calculate_num_of_tokens(string, delimiters);

	ret_array = new_string_array(ret_array_length);
	if (ret_array == NULL)
		return (NULL);

	current_token = strtok(string, delimiters);

	while (current_token != NULL)
	{
		ret_array[current_index] = string_dup(current_token);

		current_token = strtok(NULL, delimiters);
		current_index++;
	}
	free(current_token);

	return (ret_array);
}

/**
 * calculate_num_of_tokens - used to determine how many tokens string contains
 * @string: Contents of this string to be broken broken into tokens.
 * @delimiters: String containing delimiters. May vary one call to another.
 *
 * Description: REMEMBER YOU ARE ALWAYS PASSING BY REFERENCE IN C!!!!!!!!!!
 *
 * Return: number of tokens that particular string contains.
*/
size_t calculate_num_of_tokens(const char *string, const char *delimiters)
{
	size_t num_of_tokens = 0;

	char *string_copy;
	char *current_token;

	string_copy = string_dup(string);

	if (string_copy == NULL)
		return (0);

	current_token = strtok(string_copy, delimiters);

	while (current_token != NULL)
	{
		num_of_tokens++;
		current_token = strtok(NULL, delimiters);
	}
	free(string_copy);

	return (num_of_tokens);
}
