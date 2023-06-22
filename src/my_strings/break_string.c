#include "my_strings.h"

#define ORIGINAL 0
#define NEW 1

static int calculate_dividing_line(char *string, const char delimiter);

/**
 * take_right_string - returns only the part of the string right of given delim
 * @string: string we're taking the right portion of
 * @delimiter: delimiter marking the starting point of new string.
 *
 * Return: Everything to the right of the given delimter.
 */
char *take_right_string(char *string, const char delimiter)
{
	char *right_string;

	size_t string_length[2] = {0, 0};
	size_t cursor[2] = {0, 0};

	int divide = (int)calculate_dividing_line(string, delimiter);

	if ((string == NULL) || (delimiter == '\0') || (divide == -1))
		return (NULL);

	string_length[ORIGINAL] = _strlen(string);
	string_length[NEW] = string_length[ORIGINAL] - divide + 1;

	right_string = malloc(string_length[NEW] * sizeof(char));
	if (right_string == NULL)
		return (NULL);

	for (cursor[0] = divide; cursor[0] < string_length[ORIGINAL]; cursor[0]++)
		right_string[cursor[1]++] = string[cursor[0]];

	right_string[cursor[1]] = '\0';

	return (right_string);
}

/**
 * take_left_string - returns only the part of the string left of given delim
 * @string: string we're taking the left portion of
 * @delimiter: delimiter marking the starting point of new string.
 *
 * Return: Everything to the left of the given delimter.
 */
char *take_left_string(char *string, const char delimiter)
{
	char *left_string;

	size_t string_length = 0;
	size_t cursor = 0;
	
	int divide = calculate_dividing_line(string, delimiter);

	if ((string == NULL) || (delimiter == '\0') || (divide == -1))
		return (NULL);

	string_length = divide - 1;

	left_string = malloc((string_length + 1) * sizeof(char));
	if (left_string == NULL)
		return (NULL);

	for (cursor = 0; cursor < string_length; cursor++)
		left_string[cursor] = string[cursor];

	left_string[cursor] = '\0';

	return (left_string);
}

/**
 * string_contains - whether or not a string contains the delimiter at all
 * @string: string to be checked
 * @delimiter: the delimiter we're looking for
 *
 * Return: '0' for No, '1' for Yes.
*/
int string_contains(char *string, const char delimiter)
{
	return (calculate_dividing_line(string, delimiter) != -1);
}

/**
 * calculate_dividing_line - finds the index by which the string will be broken
 * @string: a string to be broken down the middle
 * @delimiter: the place it needs to be broken
 *
 * Return: Index of the character used to divide the string in two.
*/
static int calculate_dividing_line(char *string, const char delimiter)
{
	size_t i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] == delimiter)
			return ((int)i + 1);
	}
	return (-1);
}
