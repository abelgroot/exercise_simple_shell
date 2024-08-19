#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
* main - execute `ls -l /tmp` in 5 different child processes.
*
* Return: Always 0.
*/
int main(void)
{
	pid_t child_pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	for (int i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
