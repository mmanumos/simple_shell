#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

void sig_handler(int num);
int execute(char **argv, char *path);
char  *_get_env(void);
char *verify_path(char *cmd);
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

#endif
