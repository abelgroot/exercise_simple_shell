#include <stdio.h>
#include <string.h>

extern char **environ;

/**
* _getenv - gets the value of an environment variable
* @name: name of the environment variable
*
* Return: value of the environment variable, or NULL if not found.
*/
char *_getenv(const char *name)
{
	unsigned int i = 0;
	size_t len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			return (environ[i] + len + 1);
		}
		i++;
	}
	
	return (NULL);
}

/**
* main - tests the _getenv function
*
* Return: Always 0.
*/
int main(void)
{
	char *value;

	value = _getenv("USER");
	if (value)
		printf("PATH: %s\n", value);
	else
		printf("PATH not found\n");

	return (0);
}
