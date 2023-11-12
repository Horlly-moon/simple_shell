#include "shell.h"

char *search_path(char *command)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, PATH_DELIMITER);

	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(command) + 2);

		if (!full_path)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, F_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, PATH_DELIMITER);
	}

	free(path_copy);
	return (NULL);
}
