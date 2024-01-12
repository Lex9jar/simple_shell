#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define INFINITE 1
#define CHUNK 120

/* Environment Variable */
extern char **environ;
extern int _return;

/* Advance Tasks */
char *_strtok(char *str, const char *delim);

/* signals */
void handle_Ctrl_C(int sig);
void handle_Ctrl_L(int sig);

/* general_tools */
void s_printf(char *str);
void prompt(void);
void _EOF(char *lineptr, int _return);
void ctrl_c(int sig);

/* 0-string_utils */
size_t _strspn(char *s, const char *accept);
size_t _strcspn(char *s, const char *reject);
char *_strchr(const char *s, char c);
size_t word_count(char *str, const char *delim);
char *_strcat(char *dest, char *src);

/* 1-string_utils */
size_t _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, size_t n);

/* modifiers_utils */
void concate(char *path, char *cmd_line,
		char **fullpath, char *f_name);
int add_path(char **cmd, char *f_name, int *_return);
char **generate_arg_vector(size_t argc, char *cmd_line,
		const char *delim, char *f_name);
char **mod_lineptr(char *lineptr, size_t size,
		const char *delim, char *f_name, int *_return);

/* environ */
char **dup_env(char *f_name);
char *_getenv(char *name);

/* execute_commands */
int execute_commands(char *lineptr, char *f_name, int *_return);
int _execve(char **argv, char *f_name);

/* built_in */
void _printenv(void);

/* memory_utils */
char *_realloc(char *str, size_t size);
void free_array(char **array, size_t size);
void free_env(void);

/* error_msg */
void _enomem(char *f_name);

#endif /* _SHELL_H_ */
