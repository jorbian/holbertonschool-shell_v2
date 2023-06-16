#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "my_strings.h"

#define HASH_VALUE 5381
#define SIZE_OF_TABLE 255 /* TOTAL NUMBER OF SYMBOLS SUPPORTED */
#define NEXT_ELEM(var) var->next
#define FREE_ALL(symbol) do {			\
		free((symbol)->key);		\
		free((symbol)->value);		\
		free((symbol));		\
						\
	} while (0)

/**
 * struct symbol_s - An individually defined variable
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct symbol_s
{
	char *key;
	char *value;
	struct symbol_s *next;
} symbol_t;

/**
 * struct symbol_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want symboltable to use a Chaining collision handling
 */
typedef struct table_s
{
	size_t max_length;
	size_t current_length;
	symbol_t **entries;
} table_t;

extern table_t *symbol_table;

/* FUNCTION PROTOTYPES */
int create_symbol_table(size_t max_length);
size_t key_index(const unsigned char *key, size_t max_length);
static size_t hash_djb2(const unsigned char *str);
void delete_symbol_table();
size_t check_table_length();

int new_symbol(const char *key, const char *value);
static int _check_capactiy();
static symbol_t *_create_symbol(const char *key, const char *value);
static int _place_on_table(symbol_t *new_symbol);

char *retrieve_symbol_value(const char *key);
void modify_symbol_value(const char *key, char *new_value);
void swap_symbol_values(const char *key0, const char *key1);

#endif
