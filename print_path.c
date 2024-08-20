#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_dirs(void)
{
	char *path_env = getenv("PATH");
	char *dir;

	if (path_env == NULL)
	{
		perror("getenv");
		return;
	}

	/* Create a copy of path_env because strtok modifies the string */
	char *path_copy = strdup(path_env);

	if (path_copy == NULL)
	{
		perror("strdup");
		return;
	}

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
}
