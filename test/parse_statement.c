#include "include/shellv2.h"

/**
 * parse_statement - tokenize a statement into an array
 * @statement: the statement as a string
 * 
 * Return: statement broken up into individual pieces
*/
char **parse_statement(char *statement)
{
    statement = trim_whitespace(statement);

    if (string_contains(statement, ' '))
        return (has_args(statement));
    else
        return (no_args(statement));
}

/**
 * no_args - statement was detected not to have had args with it
 * @statement: a string that we are recasting as one length array
 * 
 * Return: A 1 len array containing the string.
*/
static char **no_args(char *statement)
{
    char **parsed_statement;

    parsed_statement = new_string_array(1);
    if (parsed_statement == NULL)
        return (NULL);

    parsed_statement[0] = _strdup(statement);

    //free(statement);

    return (parsed_statement);
}

/**
 * has_args - a regular staement that actually does have args
 * @statement: a string that we are recasting as one length array
 * 
 * Return: A 1 len array containing the string.
*/
static char **has_args(char *statement)
{
    char **parsed_statement;

    parsed_statement = tokenize_string(statement, " ");
    if (parsed_statement == NULL)
        return (NULL);

    return (parsed_statement);
}
