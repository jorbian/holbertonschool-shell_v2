#include "shellv2.h"

void open_repl()
{
	size_t bytes = 0;

	char *input = NULL;

	while (1)
	{
		printf("%s", PROMPT);

		if (getline(&input, &bytes, stdin) == EOF)
				break;

		parse_and_execute_input(input);
	}
}
