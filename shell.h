#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

/**
 * struct list - path directory list structure.
 * @dir: directory path.
 * @next: pointer to the next directory node.
 */
typedef struct list
{
	char *dir;
	struct list *next;
} list_t;

/* main.c */
int start_shell(list_t *path, char **env, char *program_name, int mode);
int execute_buffer(char *buffer, list_t *path, char **env,
		char *program_name);
int execute_command(char *new_buffer, list_t *path, char **env,
		int final, char *program_name);
int execute_fork(char **input, char *program_name);

/* dmemory.c */
char *get_path(char *buffer, list_t **path);
char *aux_get_path(list_t *list_pointer,
	char *slash_command, char *slash_input, char *input);
char *clean_spaces(char *buffer);
char **create_argv(char *input_buffer, list_t **path);
void free_argv(char **argv);

#endif /* SHELL_H */
