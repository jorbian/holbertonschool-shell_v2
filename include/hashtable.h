#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#include "my_strings.h"

#define HASH_VALUE 5381
#define SIZE_OF_TABLE 255 /* TOTAL NUMBER OF SYMBOLS SUPPORTED */
#define NEXT_ELEM(var) var->next
#define FREE_ALL_SNODES(node) do {			\
		free((node)->key);		\
		free((node)->value);		\
		free((node));		\
						\
	} while (0)

/**
 * struct node_s - An individually defined variable
 *
 * @key: String used to be assosiated with the value
 * @value: Void poitner to value of table's datatype
 * @next: A pointer to the next node of the List
 */
typedef struct node_s
{
	char *key;
	char *value;
	struct node_s *next;
} node_t;

/**
 * struct table_s - Hash table data structure
 *
 * @max_length: The size of the array
 * @current_length: Maximum number of nodes table can hold.
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want nodetable to use a Chaining collision handling
 */
typedef struct table_s
{
	size_t max_length;
	size_t current_length;
	node_t **array;
} table_t;

extern table_t *symbol_table;

table_t *create_hash_table(size_t max_length);
void delete_hash_table(table_t *hash_table);

int create_new_node(table_t *string_table, const char *key, const char *value);
void list_all_nodes(table_t *table);
size_t key_index(const unsigned char *key, size_t max_length);
char *retrieve_value(table_t *table, const char *key);
void swap_node_values(table_t *table, const char *key0, const char *key1);
void modify_node(table_t *table, const char *key, char *new_value);
int create_new_node(table_t *table, const char *key, const char *value);
char **cast_to_array(table_t *table);

#endif
