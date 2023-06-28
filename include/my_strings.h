#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define FIRST_CHAR(str) ((int)(str[0])) /* decimal value of first char */
#define NTH_CHAR(str, idx) ((int)(str[idx])) /* same but anywhere else */
#define IS_ALPHA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define IS_NUMERIC(c) (c >= '0' && c <= '9')
#define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUMERIC(c))
#define IS_SPACE(c) (c == ' ' || c == '\t' || c == '\n')
#define TOLOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)
#define TOUPPER(c) ((c >= 'a' && c <= 'z') ? (c + ('A' - 'a')) : c)

/* VARIOUS REINVENTIONS OF THE WHEEL */
char *_strdup(const char *old_string);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
void *_memcpy(void *destination, const void *source, size_t num);
int _atoi(char *s);

/* LIFE AND DEATH OF STRING ARRAYS */
char **new_string_array(size_t length);
void free_string_array(char **array);
void list_string_array(char **array);
char **search_array(size_t length, char **array, int (*terms)(const char *));
size_t ping_matches(size_t length, char **array, int (*terms)(const char *));
size_t calculate_num_of_tokens(const char *string, const char *delimiters);
char **tokenize_string(char *string, const char *delimiters);

char *trim_whitespace(char *str);
char *take_right_string(char *string, const char delimiter);
char *take_left_string(char *string, const char delimiter);
int string_contains(char *string, const char delimiter);

int is_only_spaces(char *string);
char *trim_whitespace(char *str);
char *take_input();

#endif
