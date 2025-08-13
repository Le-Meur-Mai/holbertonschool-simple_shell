#include "main.h"

/**
 * main- Start of the program simple shell, who behave with less options, like
 * a shell.
 * @argc: Number of arguments passed in function
 * @argv: Array which contain all the arguments passed in function
 * @env: Points to an array that contain all the environnment variables
 * available to the process
 * Return: -1 on failure, 0 on success
 */

int main(int argc, char *argv[], char **env)
{
	ssize_t check = 0;
	size_t size_buffer = 0;
	char *line = NULL;
	pid_t my_pid;
	int status;
	(void)argc;

	while (1)
	{
		printf("#Cisfun$ ");
		check = getline(&line, &size_buffer, stdin);
		if (check < 0)
		{
			printf("exit\n");
			return (-1);
		}
		else
		{
			my_pid = fork();
			if (my_pid == -1)
				printf("./shell: Can't start the program\n");
			else if (my_pid == 0)
			{
				line[(string_lenght(line) - 1)] = '\0';
				if (execve(line, argv, env) == -1)
				{
					printf("./shell: No such file or directory\n");
					return (-1);
				}
				return (0);
			}
			wait(&status);
		}
	}
	free(line);
	return (0);
}
