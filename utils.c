#include "shell.h"

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}

char **split_line(char *line)
{
	char *token;
	int bufsize = BUFSIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITER);

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_DELIMITER);
	}

	tokens[position] = NULL;
	return (tokens);
}
