#include "main.h"
/**
 * argv_for_shell- Function that create an array of arguments string, based on
 * a line of command given.
 * @line: Line of command given you want to put in an array of arguments
 * Return: An array similar to argv[], who has string of arguments in it.
 */
char **argv_for_shell(char *line)
{
	char *argument_string;
	char *separators = "	 ";
	int i = 0;
	char **_argv = malloc(sizeof(char *) * 64);

	if (line == NULL)
	{
		free(_argv);
		return (NULL);
	}

	if (_argv == NULL)
	return (NULL);
	argument_string = strtok(line, separators);
	while (argument_string != NULL)
	{
		_argv[i++] = argument_string;
		argument_string = NULL;
		argument_string = strtok(NULL, separators);
	}
	_argv[i] = NULL;
	if (_argv == NULL)
	{
		free(_argv);
		return (NULL);
	}
	return (_argv);
}
