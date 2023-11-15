#include "shell.h"

/**
 * main - Entry point for the custom shell program.
 *
 * Return: Always 0 on successful execution.
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = execute_command(args);

		free(line);
		free(args);
	}
		while
			(status);

		return (0);
}
