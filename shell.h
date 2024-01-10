#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define INFINITE 1
#define _WIFEXITED(status) (((status) & 0xFF) == 0)
#define _WEXITSTATUS(status) (((status) >> 8) & 0xFF)

/* Environment Variable */
extern char **environ;

/* general_tools */
void shell_printf(char *str);
void prompt(void);
void _EOF(char *lineptr);

/* string_utils */
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* execute_commands */
int execute_commands(char **argv, char *f_name);

#endif /* _SHELL_H_ */
