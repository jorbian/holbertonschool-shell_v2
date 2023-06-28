#include "hashtable.h"

static size_t hash_djb2(const unsigned char *str);

/**
 * key_index - returns location to store value in symbol table
 * @key: string to store
 * @max_length: number of elements in table
 *
 * Return: location to store @key
 */
size_t key_index(const unsigned char *key, size_t max_length)
{
	return (hash_djb2(key) % max_length);
}

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 * Return: hash value
 */
static size_t hash_djb2(const unsigned char *str)
{
	size_t hash;
	int c;

	hash = HASH_VALUE;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return (hash);
}
