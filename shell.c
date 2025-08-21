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
	ssize_t check, code_exit = 0;
	size_t size_buffer = 0, j = 1;
	char *line = NULL, **_argv = NULL;
	(void)ac;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			printf("($) ");
			fflush(stdout);
		}
		check = getline(&line, &size_buffer, stdin);
		if (check == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				printf("\n");
			free_arguments(_argv, line);
			break;
		}
		line[(strlen(line) - 1)] = '\0';
		_argv = argv_for_shell(line);
		if (verif_built_in(line, _argv, env, code_exit) == 1)
		{
			code_exit = executing_program(_argv, env);
			if (code_exit == 127)
				fprintf(stderr, "%s: %ld: %s: not found\n", av[0], j, _argv[0]);
			else if (code_exit == 126)
				fprintf(stderr, "%s : %s found but not executable\n", av[0], _argv[0]);
		}
		free_arguments(_argv, line);
		line = NULL, _argv = NULL;
		j++;
	}
	return (code_exit);
}
