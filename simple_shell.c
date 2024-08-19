#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

/**
* main - super simple shell
*
* Return: Always 0.
*/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			perror("Error:");
			free(line);
			exit(EXIT_FAILURE);
		}

		line[nread - 1] = '\0';

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork error");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			if (execve(line, NULL, NULL) == -1)
			{
				perror("Execve error");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return 0;
}
