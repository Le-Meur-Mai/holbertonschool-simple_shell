#include "main.h"

/**
 * verif_command- verify if a command is a built-in
 * @line: line of command
 * @_argv: Array of arguments
 * @env: environment variable
 * @code_exit: exit code of the last command
 * Return: 1 if the command is a built-in, 0 if not
 */

int verif_built_in(char *line, char **_argv, char **env, ssize_t code_exit)
{
	if (_argv == NULL || _argv[0] == NULL || (strcmp(_argv[0], "\n") == 0))
	{
		return (1);
	}

	if (strcmp(_argv[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}

	if (strcmp(_argv[0], "exit") == 0)
	{
		free_arguments(_argv, line);
		exit(code_exit);
	}
	return (0);
}
