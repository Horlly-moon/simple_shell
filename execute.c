#include "shell.h"

// This function executes the specified command provided in the 'args' array.
int execute_command(char **args)
{
	char *path;


	// This function executes the specified command provided in the 'args' array.
	if (args[0] == NULL)
	{
		return (1);
	}

	 // Check if the command is "exit." If so, exit the shell gracefully.
	if (strcmp(args[0], "exit") == 0)
	{
		free(args);// Free the memory allocated for the 'args' array.
		exit(EXIT_SUCCESS); // Terminate the shell with a successful status code.
    }
	}

	 // Check if the command is "env." If so, print environment variables.
	if (strcmp(args[0], "env") == 0)
	{
		char **env = environ;

	 // Print each environment variable to the standard output.
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1); // Return 1 to indicate the command was handled.
	}

	 // Search for the full path to the command using the 'search_path' function.
	path = search_path(args[0]);
	if (path != NULL)
	{
		pid_t pid = fork();// Fork a new process.

		if (pid == 0)
		{
			 // In the child process, attempt to execute the command.
			if (execve(path, args, environ) == -1)
			{
				perror("execve error");// Print an error message if execution fails.
				exit(EXIT_FAILURE);// Exit the child process with a failure status.
			}
		}

		else if (pid < 0)
		{
			perror("fork error");// Print an error message if forking fails.
		}

		else
		{
			wait(NULL);// In the parent process, wait for the child process to complete.
		}
		free(path);// Free the memory allocated for the 'path' variable.
	}

	else
	{
		// If the command is not found, print an error message to stderr.
		fprintf(stderr, "Command not found: %s\n", args[0]);
	}

	return (1); // Return 1 to indicate the command was handled.
}
