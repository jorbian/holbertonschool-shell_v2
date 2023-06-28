#include "hsh.h"

static char *find_command_path(char *command_string);
static void (*check_builtins(char *command_name))(char **);
static char *create_test_path(char *dir_path, char *command);
static void create_new_process(char *cmd_path, char **command_args);

/**
 * process_command - parses an individual line taken from a script or the REPL
 * @new_line: the new line to be parsed
 *
 * Description: WILL REQUIRE SIGNIFICANT OVERHALL TO SUPPORT PIPES!!!
*/
void process_command(char *new_line)
{
	char **tokenized_line = NULL;
	char *command_path = NULL;

	void (*builtin)(char **);

	tokenized_line = tokenize_string(trim_whitespace(new_line), " ");

	free(new_line);

	builtin = check_builtins(tokenized_line[0]);

	if (builtin != NULL)
		builtin(tokenized_line);
	else
	{
		command_path = find_command_path(tokenized_line[0]);
		if (command_path != NULL)
			create_new_process(command_path, tokenized_line);

		free(command_path);
	}
	free_string_array(tokenized_line);
}

/**
 * check_builtins - runs down the list of builtins to see if name matches
 * @command_name: the command name being evaluated
 *
 * Return: the function pointer which invokes that builtin, if it is one,
 * or just NULL if there isn't.
*/
static void (*check_builtins(char *command_name))(char **)
{
	size_t index = 0;

	int difference = -1;

	char builtin_names[NUM_OF_BILTNS][BLTN_NAME_LEN] = BUILTIN_NAMES;

	void (*func_ptrs[NUM_OF_BILTNS])(char **args) = BUILTIN_FPTRS;

	for (; index < NUM_OF_BILTNS; index++)
	{
		difference = _strcmp(command_name, builtin_names[index]);
		if (difference == 0)
			return (func_ptrs[index]);
	}
	return (NULL);
}

/**
 * find_command_path - attempts to find executable path to argv[0]
 * @command_string: the first string of non whitespace characters entered
 *
 * Return: pointer if found, NULL not found
 */
static char *find_command_path(char *command_string)
{
	struct stat file_info;
	char *command_path;
	char *test_path;
	int i = 0;

	command_path = malloc(sizeof(char) * 255);

	sprintf(command_path, "%s", command_string);

	while (path[i])
	{
		if (stat(command_path, &file_info) == 0)
			return (command_path);

		test_path = create_test_path(
				path[i++],
				command_string
		);
		sprintf(command_path, "%s", test_path);
		free(test_path);
	}
	free(command_path);

	return (NULL);
}

/**
 * create_test_path - Concatenate command argv[0] to each directory path
 * @dir_path: pointer a one dir PATH
 * @command: command
 *
 * Return: pointer string dir + cmd or NULL error
 */
static char *create_test_path(char *dir_path, char *command)
{
	int dir_path_len, command_len, total_path_len;

	int i = 0, j = 0;
	char *test_path;

	dir_path_len = _strlen(dir_path);
	command_len = _strlen(command);
	total_path_len = dir_path_len + command_len;

	test_path = malloc(sizeof(char) * total_path_len + 2);

	while (dir_path[i])
	{
		test_path[i] = dir_path[i];
		i++;
	}
	test_path[i] = '/';
	i++;
	while (command[j])
		test_path[i++] = command[j++];

	test_path[i] = '\0';

	return (test_path);
}

/**
 * create_new_process - Forks a child process that is possessed by our argv
 * @command_path: filepath to executable to be invoked.
 * @command_args: arguments to be passed to a process we're going to fork.
 *
 * Return: void
 */
static void create_new_process(char *command_path, char **command_args)
{
	pid_t id;
	int status;

	char **environs = cast_to_array(symbol_table);

	id = fork();
	if (id == -1)
		perror("Fork failed");
	else if (id > 0)
		wait(&status);
	else if (id == 0)
		execve(command_path, command_args, environs);
	if ((WIFEXITED(status)))
		exit_status = WEXITSTATUS(status);
	if (id != 0)
	{
		fflush(stdout);
		fflush(stdin);
	}

	free_string_array(environs);
}
