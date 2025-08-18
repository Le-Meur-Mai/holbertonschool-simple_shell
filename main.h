#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *_which(char *command_name);
char *_getenv(const char *name);
char **argv_for_shell(char *line);
void free_arguments(char **_argv, char *line);
int executing_program(char *line, char **_argv, char **env);

#endif
