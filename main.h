#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

char *_wich(char *line);
char *_getenv(const char *name);
int string_lenght(char *string);

#endif
