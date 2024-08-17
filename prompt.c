#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
* main - Entry point of the program
*
* Return: Always 0.
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

	/* Read a line from standard input */
	nread = _getline(&line, &len, STDIN_FILENO);

	/* Handle EOF or error */
	if (nread == -1)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		else
		{
			perror("_getline");
			break;
		}
	}

	/* Write the read line to standard output */
	write(STDOUT_FILENO, line, nread);
	}

	free(line);
	return (0);
}
