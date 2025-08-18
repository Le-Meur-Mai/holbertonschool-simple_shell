#include "main.h"

/**
 * main- Start of the program simple shell, who behave with less options, like
 * a shell.
 * @ac: Number of arguments passed in function
 * @av: Array which contain all the arguments passed in function
 * @env: Points to an array that contain all the environnment variables
 * available to the process
 * Return: -1 on failure, 0 on success
 */

int main(int ac, char **av, char **env)
{
	ssize_t check = 0;
	size_t size_buffer = 0;
	char *line = NULL;
	char **_argv = NULL;
	pid_t my_pid;
	int status;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			printf("($) ");
		check = getline(&line, &size_buffer, stdin);
		if (check == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				printf("exit\n");
			break;
		}
			line[(strlen(line) - 1)] = '\0';
			_argv = argv_for_shell(line);
			my_pid = fork();
			if (my_pid == -1)
				printf("Can't strat the program\n");
			else if (my_pid == 0)
			{
				if (execve(line, _argv, env) == -1)
				{
					printf("%s: 1: %s: not found\n", av[0], _argv[0]);
					return (-1);
				}
				return (0);
			}
			wait(&status);
	}
	free(_argv);
	free(line);
	return (0);
}
