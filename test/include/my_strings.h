#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_CHAR(str) ((int)(str[0])) /* decimal value of first char */
#define NTH_CHAR(str, idx) ((int)(str[idx])) /* same but anywhere else */
#define IS_ALPHA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define IS_NUMERIC(c) (c >= '0' && c <= '9')
#define IS_ALPHANUM(c) (IS_ALPHA(c) || IS_NUMERIC(c))
#define IS_SPACE(ch) (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\v' || ch == '\f')
#define TOLOWER(c) ((c >= 'A' && c <= 'Z') ? (c + ('a' - 'A')) : c)
#define TOUPPER(c) ((c >= 'a' && c <= 'z') ? (c + ('A' - 'a')) : c)

/* VARIOUS REINVENTIONS OF THE WHEEL */
char *_strdup(const char *old_string);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
void _strcpy(char *dest, const char *src);
void *_memcpy(void *destination, const void *source, size_t num);


char *trim_whitespace(char *str);
char *take_right_string(char *string, const char delimiter);
char *take_left_string(char *string, const char delimiter);
int string_contains(char *string, const char delimiter);
static int calculate_dividing_line(char *string, const char delimiter);

#endif
