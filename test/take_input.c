#include "include/shellv2.h"

#define INPUT_BUFF 255

/**
 * take_input - takes a line of input from the user
 * 
 * Return: pointer to string containing the input
*/
char *take_input(void)
{
    char *line_buffer;

    size_t buffer_size = INPUT_BUFF;

    line_buffer = (char *)malloc(buffer_size * sizeof(char));
    if (line_buffer== NULL)
        return (NULL);

    getline(&line_buffer, &buffer_size, stdin);

    return (line_buffer);
}


void open_repl(void)
{
    
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

    while(IS_SPACE((unsigned char)*str))
        str++;

    if(*str == 0)
        return str;

    end = str + _strlen(str) - 1;

    while(end > str && IS_SPACE((unsigned char)*end))
        end--;

    end[1] = '\0';

    return (str);
}
