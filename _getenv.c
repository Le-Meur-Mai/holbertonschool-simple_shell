#include "main.h"

/**
 * _getenv- Fincd environment variable you need
 * @name: Name of the environment variable
 * @env: Environment variable
 * Return: A pointer to a the string that the environment variable is associate
 * with
 */


char *_getenv(const char *name, char **env)
{
	int i = 0;

	size_t length = strlen(name);

	if (name == NULL)
		return (NULL);

	for (; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name, length) == 0 && env[i][length] == '=')
			return (&env[i][length + 1]);
	}
	printf("Variable not found\n");
	return (NULL);
}
