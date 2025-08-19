#include "main.h"

/**
 * _which- function that found the absolute path of a command
 * @command_name: command you wan to know the absolute path
 * @env: Environment variable
 * Return: NULL if the command doesn't exist or the asolute path of the command
 */


char *_which(char *command_name, char **env)
{
	char *separator = ":";
	char *strtoken = NULL;
	char *the_path = strdup(_getenv("PATH", env));
	char *path_complete = NULL;
	struct stat st;
	size_t len = 0;

	strtoken = strtok(the_path, separator);
		while (strtoken != NULL)
		{
			len = strlen(strtoken) + strlen(command_name) + 2;
			path_complete = malloc(len);
			if (path_complete == NULL)
			{
				printf("mallocNULL");
				free(the_path);
				return (NULL);
			}
			path_complete[0] = '\0';
			strcat(path_complete, strtoken);
			strcat(path_complete, "/");
			strcat(path_complete, command_name);
			/*FusionDestrtoken+/+line*/
			if (stat(path_complete, &st) == 0)
			{
				free(the_path);
				return (path_complete);
			}
			strtoken = strtok(NULL, separator);
			free(path_complete);
			path_complete = NULL;
		}
	free(the_path);
	return (NULL);
}
