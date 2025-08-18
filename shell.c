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
	char *line = NULL, **_argv = NULL;
	pid_t my_pid;
	int status;
	struct stat st;
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
			if (stat(_argv[0], &st) == -1 && isatty(STDIN_FILENO) == 1)
				printf("%s: No such file or directory\n", av[0]);
			else if ((my_pid = fork()) == 0)
			{
				if (execve(line, _argv, env) == -1)
				{
						printf("%s: 1: %s: not found\n", av[0], _argv[0]);
						return (-1);
				}
				return (0);
			}
			if (my_pid == -1)
				printf("Can't start the program\n");
			wait(&status);
	}
	free(_argv);
	free(line);
	return (0);
}
