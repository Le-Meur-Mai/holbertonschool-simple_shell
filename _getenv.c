#include "main.h"

/**
 * _getenv- Fincd environment variable you need
 * @name_var: Name of the environment variable
 * @env: Environment variable
 * Return: A pointer to a the string that the environment variable is associate
 * with
 */


char *_getenv(const char *name_var, char **env)
{
	int i = 0;
	size_t length = 0;

	if (name_var == NULL)
		return (NULL);

	length = strlen(name_var);

	for (; env[i] != NULL; i++)
	{
		if (strncmp(env[i], name_var, length) == 0 && env[i][length] == '=')
			return (&env[i][length + 1]);
	}
	printf("Variable not found\n");
	return (NULL);
}
