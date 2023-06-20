#include "shellv2.h"

void parse_and_execute_input(char *user_input)
{
    char **tokenized_input;

    tokenized_input = tokenize_string(user_input, " ");
    if (tokenized_input == NULL)
        return;

    list_string_array(tokenized_input);

    free_string_array(tokenized_input);
}
