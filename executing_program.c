#include "main.h"
/**
 * executing_program- execute a program with the line and the arguments given.
 * @line: command given
 * @_argv: array of arguments of the command
 * @env : environment variable
 * Return: 11 on failure, 0 on success
 */

int executing_program(char *line, char **_argv, char **env)
{
	struct stat _stat;
	char *path_of_command = _which(_argv[0], env);
	pid_t my_pid;
	int status;

	if (stat(_argv[0], &_stat) == 0 || path_of_command != NULL)
	{
		my_pid = fork();
		if (my_pid == 0 && path_of_command == NULL)
		{
			if (execve(line, _argv, env) == -1)
				exit(2);
		}
		else if (my_pid == 0 && path_of_command != NULL)
		{
			if (execve(path_of_command, _argv, env) == -1)
				exit(2);
		}
		else if (my_pid == -1)
		{
			printf("fork failed\n");
			free(path_of_command);
			return (126);
		}
	wait(&status);
	}
	else
	{
		free(path_of_command);
		return (127);
	}
	free(path_of_command);
	return (_Wexitstatus(status));
}
