#include "main.h"

/**
 * _getenv- Fincd environment variable you need
 * @name: Name of the environment variable
 * Return: A pointer to a the string that the environment variable is associate
 * with
 */


char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;

	size_t length = strlen(name);

	if (name == NULL)
		return (NULL);

	for (; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, length) == 0 && environ[i][length] == '=')
			return (&environ[i][length + 1]);
	}
	printf("Variable not found\n");
	return (NULL);
}
