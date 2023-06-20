#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdlib.h>

#include "my_strings.h"

#define FIRST_CHAR(str) ((int)(str[0])) /* decimal value of first char */
#define NTH_CHAR(str, idx) ((int)(str[idx])) /* same but anywhere else */

char **new_string_array(size_t length);
void free_string_array(char **array);
void list_string_array(char **array);

size_t calculate_num_of_tokens(const char *string, const char *delimiters);
char **tokenize_string(char *string, const char *delimiters);

#endif
