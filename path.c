#include "shell.h"

/**
 * search_path - Search for the full path of an executable command.
 * @command: The command to search for in the directories of the PATH variable.
 *
 * Return: If the command is found, return the full path;otherwise, returnNULL.
 */
char *search_path(char *command)
{
	char *path = getenv("PATH"); /* Get the PATH environment variable. */
	char *path_copy = strdup(path); /* Create a copy of the PATH variable. */
	char *dir = strtok(path_copy, PATH_DELIMITER); /*Tokenize thePATHstring. */

	/* Loop through each directory in the PATH. */
	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(command) + 2);

		/* Check for memory allocation errors. */
		if (!full_path)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}

		/* Construct the full path by combiningthe directory and the command. */
		sprintf(full_path, "%s/%s", dir, command);

		/* Check if the file at the path exists (F_OK indicates existence). */
		if (access(full_path, F_OK) == 0)
		{
			free(path_copy); /* Free the copied PATH string. */
			return (full_path); /*Returnfull path if thecommand isfound.*/
		}

		free(full_path); /* Free the memory allocated for the full path. */
		dir = strtok(NULL, PATH_DELIMITER); /*Moveon next dir in thePATH.*/
	}

	free(path_copy); /* Free the copied PATH string if the command is not found.*/
	return (NULL); /* Return NULL to indicate that the command was not found. */
}
