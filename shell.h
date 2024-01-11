#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define INFINITE 1

/* Environment Variable */
extern char **environ;

/* general_tools */
void shell_printf(char *str);
void prompt(void);
void _EOF(char *lineptr);
void ctrl_c(int sig);

/* 0-string_utils */
size_t _strspn(char *s, const char *accept);
size_t _strcspn(char *s, const char *reject);
char *_strchr(const char *s, char c);
char *trim(char *str);
size_t word_count(char *str, const char *delim);

/* 1-string_utils */
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, size_t n);

/* modifiers_utils */
char **generate_arg_vector(size_t argv, char *cmd_line,
		const char *delim, char *f_name);

/* execute_commands */
int execute_commands(char *lineptr, char *f_name);
int _execve(char **argv, char *f_name);

/* memory_utils */
void free_array(char **array, size_t size);

/* error_msg */
void _enomem(char *f_name);

#endif /* _SHELL_H_ */
