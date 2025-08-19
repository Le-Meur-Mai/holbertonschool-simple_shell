#include "main.h"

/**
 * free_arguments- Function that free the array of arguments and the line of
 * arguments.
 * @_argv: Array of arguments
 * @line: line of command
 */
void free_arguments(char **_argv, char *line)
{
	if (_argv != NULL)
		free(_argv);
	if (line != NULL)
		free(line);
}
