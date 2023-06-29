#include "hsh.h"

static void launch_repl(void);
static void read_script(void);

char **path;
int exit_status = 0;
int line_num = 0;
table_t *symbol_table;

/**
 * main - the entry point for the shell
 * @argc: number of arguments passed to the program
 * @argv: array containing whatever those arguments were
 * @envp: array containing the enviornmental variables
 *
 * Return: Always returns 0
*/
int main(int argc, char **argv, char **envp)
{
	initalize_shell(argc, argv, envp);

	if (isatty(STDIN_FILENO))
		launch_repl();
	else
		read_script();

	deinitalize_shell();

	return (0);
}

/**
 * launch_repl - open a READ-EVALUATE-PRINT-LOOP with interpreter
 *
 * Return: void (for now)
 */
static void launch_repl(void)
{
	char *line = NULL;

	while (1)
	{
		printf("($) ");
		line = take_input();
		process_command(line);
		fflush(NULL);
	}
}

/**
 * read_script - read a script as piped in from stdin
 *
 * Return: void.
 */
static void read_script(void)
{
	char *current_line = NULL;

	int more_input = TRUE;

	do {
		current_line = take_input();

		if (current_line != NULL)
			process_command(current_line);
		else
			more_input = FALSE;

		fflush(NULL);

	} while (more_input == TRUE);
}
