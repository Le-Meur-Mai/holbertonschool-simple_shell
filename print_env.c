#include "main.h"

/**
 * print_env- print the environment variable
 * @env: environment variable
 */

void print_env(char **env)
{
	int i = 0;

	if (env[i] == NULL)
	return;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
