#include "main.h"

/**
 * print_env- print the environment variable
 * @env: environment variable
 * Return: return 2 on error, return 1 on success
 */

int print_env(char **env)
{
	int i = 0;

	if (env[i] == NULL)
	{
		fprintf(stderr, "Environment variable not found\n");
		return (2);
	}
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (1);
}
