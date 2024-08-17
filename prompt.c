#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = _getline(&line, &len, stdin);

	if (nread == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		else 
		{
		perror("getline");
		break;
		}
	}

		printf("%s", line);
	}
	free(line);
	return (0);
}
