#include "my_strings.h"

#define INPUT_BUFF 255

/**
 * take_input - Receives input and makes it safe to process
 * Return: Parsed input from the user
 */
char *take_input()
{
	char *buffer;
	size_t n = 1;
	ssize_t check;
	char new_line[] = {'\n', '\0'};

	buffer = malloc(sizeof(char) * INPUT_BUFF);

	check = (getline(&buffer, &n, stdin));
	if (check == -1)
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[0] == '\n' && buffer[1] == '\0')
		;
	else
	{
		buffer = strtok(buffer, new_line);
		if ((is_only_spaces(buffer)))
		{
			buffer[0] = '\n';
			buffer[1] = '\0';
		}
	}
	return (buffer);
}

/**
 * is_only_spaces - Checks if a string contains only spaces
 * @string: The string to check
 * Return: 1 if the string is only spaces, 0 otherwise
 */

int is_only_spaces(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		if (!IS_SPACE((unsigned char)*string))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * trim_whitespace - removes both trailiing and leading whitespace from string
 * @str: a string that needs to be adjusted
 *
 * Return: String sans whitespace
*/
char *trim_whitespace(char *str)
{
	char *end;

	while (IS_SPACE((unsigned char)*str))
		str++;

	if (*str == 0)
		return (str);

	end = str + _strlen(str) - 1;

	while (end > str && IS_SPACE((unsigned char)*end))
		end--;

	end[1] = '\0';

	return (str);
}
