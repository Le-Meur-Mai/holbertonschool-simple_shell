#include "main.h"

/**
 * print_env- print the environment variable
 * @env: environment variable
 */

int print_env(char **env)
{
	int i = 0;

	if (env[i] == NULL)
	return (2);

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (1);
}
