#include "hsh.h"

/**
 * execute_command - runs execve on the command name
 * @cmd: the command to be executed
 * @status: the status of the shell
 * 
 * Return: the status of the executed command
 */
int execute_command(char *command_name, char **args, int status)
{
	pid_t check_process;

	check_process = fork();
	if (check_process < 0)
	{
		perror("Could not create child process");
		return (FAILURE);
	}
	if (check_process == 0)
	{
		if (execve(command_name, (args + 1), NULL) == -1)
			perror("Command could not execute");
	}
	else
	{
		wait(&status);
		/* status = WEXITSTATUS(status);*/
		return (status);
	}
	return (status);
}
