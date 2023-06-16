#include "include/symbol_table.h"

/**
 * new_symbol - sets an element of a hash table
 * @key: search object to indicate @value
 * @value: value to store per key
 * Return: 0 on success, 1 on fail
 */
int new_symbol(const char *key, const char *value)
{
	size_t i;
	symbol_t *new_symbol;

	int at_capacity = _check_capactiy();

	if (!symbol_table || !key || *key == '\0' || at_capacity)
		return (EXIT_FAILURE);

	new_symbol = _create_symbol(key, value);
	if (new_symbol == NULL)
		return (EXIT_FAILURE);

	return (_place_on_table(new_symbol));
}

/**
 * _create_symbol - allocates memory for individual symbol and initalizes mems
 * @key: the string representing the symbol
 * @value: the value an an individual symbol is supposed to represent
 *
 * Return: Pointer to the newly created symbol.
*/
static symbol_t *_create_symbol(const char *key, const char *value)
{
	symbol_t *new_symbol;

	new_symbol = malloc(sizeof(symbol_t));
	if (new_symbol == NULL)
		return (NULL);

	new_symbol->key = _strdup(key);
	new_symbol->value = _strdup(value);
	new_symbol->next = NULL;

	return (new_symbol);
}

/**
 * _place_on_table - puts the symbol where it needs to go on table
 * @new_symbol: pointer to the symbol we're creating
 *
 * Return: EXIT_SUCESS '0' (if nothing goes wrong) --
 * EXIT_FAILURE '1' (if something does)
*/
static int _place_on_table(symbol_t *new_symbol)
{
	size_t i;

	symbol_t *current_symbol;

	i = key_index((unsigned char *)new_symbol->key, symbol_table->max_length);

	current_symbol = symbol_table->entries[i];

	if (current_symbol)
	{
		if (_strcmp(current_symbol->key, new_symbol->key) == 0)
		{
			new_symbol->next = current_symbol;
			symbol_table->entries[i] = new_symbol;
			return (EXIT_FAILURE);
		}
		while (current_symbol->next)
		{
			if (_strcmp(current_symbol->next->key, new_symbol->key) == 0)
			{
				NEXT_ELEM(new_symbol) = NEXT_ELEM(current_symbol->next);
				FREE_ALL(NEXT_ELEM(current_symbol));
				NEXT_ELEM(current_symbol) = new_symbol;
				return (EXIT_FAILURE);
			}
			current_symbol = current_symbol->next;
		}
	}
	NEXT_ELEM(new_symbol) = symbol_table->entries[i];
	symbol_table->entries[i] = new_symbol;
	symbol_table->current_length++;

	return (EXIT_SUCCESS);
}

/**
 * check_capactiy - true or false whether or not the table is at capacity
 * 
 * Return: '1' for True, '0' for False
*/
static int _check_capactiy()
{
	return (
		symbol_table->current_length >= symbol_table->max_length
	);
}
