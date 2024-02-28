#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define TOK_SIZE 64
#define DELIM " \n\t"
char *read_line(void);
char **token_line(char *line);
char *get_path(char *arg);
int execute_line(char **args, char **envp);
int m_exit(void);
int m_cd(char **args);
int m_env(char **env);
#endif /*MAIN_H*/
