#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* split_string - Splits a string into words
* @str: The string to split
*
* Return: A NULL-terminated array of words, or NULL if it fails
*/
char **split_string(char *str)
{
	int i = 0, size = 10;
	char *token;
	char **words = malloc(sizeof(char *) * size);

	if (words == NULL)
	{
		perror("Unable to allocate memory");
		exit(1);
	}

	token = strtok(str, " \t\n");
	while (token != NULL)
	{
		if (i >= size)
		{
			size *= 2; /* Double the size */
			words = _realloc(words, sizeof(char *) * i, sizeof(char *) * size);
			if (words == NULL)
			{
				perror("Unable to reallocate memory");
				exit(1);
			}
		}

		words[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (words[i] == NULL)
		{
			perror("Unable to allocate memory");
			exit(1);
		}
		strcpy(words[i], token);
		token = strtok(NULL, " \t\n");
		i++;
	}
	words[i] = NULL; /* Null-terminate the array */

	return (words);
}
