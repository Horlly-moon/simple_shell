#include "shell.h"

/**
 * execute_command - Execute a shell command.
 * @args: Array of command and its arguments.
 *
 * Return: 1 on success, signaling the shell to continue.
 */
int execute_command(char **args)
{
	char *path;

	 /* Check if the command is NULL */
	if (args[0] == NULL)
	{
		return (1);
	}

	 /* Handle the "exit" command */
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
	}

	path = search_path(args[0]);
	if (path != NULL)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			if (execve(path, args, environ) == -1)
			{
				perror("execve error");
				exit(EXIT_FAILURE);
			}
		}

		else if (pid < 0)
		{
			perror("fork error");
		}

		else
		{
			wait(NULL);
		}
		free(path);
	}

	else
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
	}

	return (1);
}
