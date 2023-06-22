#include "my_strings.h"

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
		ret_array[current_index] = _strdup(current_token);

		current_token = strtok(NULL, delimiters);
		current_index++;
	}
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

	string_copy = strdup(string);

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