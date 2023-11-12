#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>

#define BUFSIZE 1024
#define TOKEN_DELIMITER " \t\r\n\a"
#define PATH_DELIMITER ":"

extern char **environ;

int execute_command(char **args);
char *read_line(void);
char **split_line(char *line);
char *search_path(char *command);

#endif
