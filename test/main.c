#include "include/shellv2.h"

/**
 * main - entry point for the program
 * @argc: number of args passed to the program
 * @argv: array containing what those args were
 * @envp: array conining enviornmental variables
 * 
 * Return: Whatever the exit status of the program was

int main(int argc, char **argv, char **envp)
{
    int is_interactive = isatty(STDIN_FILENO);

    initalize_shell(argc, argv, envp);

    if (is_interactive)
        launch_repl();
    else
        read_script();

    deinitalize_shell();

    return (exit_status);
}
*/