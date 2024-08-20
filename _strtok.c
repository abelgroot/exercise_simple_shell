#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * my_strchr - Checks if a character is in the delimiter string
 * @str: The string to search in
 * @ch: The character to search for
 * Return: 1 if character is found, 0 otherwise
 */
int my_strchr(const char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (1);
		str++;
	}
	return (0);
}

/**
 * my_strtok - Tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter string
 * Return: A pointer to the next token or NULL
 */
char *my_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *token;

	if (str)
		buffer = str;
	else if (!buffer)
		return (NULL);

	// Skip leading delimiters
	while (*buffer && my_strchr(delim, *buffer))
		buffer++;

	if (!*buffer)
		return (NULL);

	token = buffer;

	// Find the end of the token
	while (*buffer && !my_strchr(delim, *buffer))
		buffer++;

	if (*buffer)
	{
		*buffer = '\0';
		buffer++;
	}

	return (token);
}
/**
 * main - Entry point
 *  shell$ ejejje dsjkj
 * Return: 0 on success, -1 on failure
 */
int main(void)
{
	char *token = 0;
	char *new_str, *delim = NULL;
	int i = 0, k = 0;
	char *str = "this is a	good ide";
	
	while (str[i] != '\0')
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	if (new_str == NULL)
		return (-1);
	for (k = 0; k < i; k++)
		new_str[k] = str[k];
	new_str[k] = '\0';
	token = my_strtok(new_str, " \t");
	while (token)
	{
		printf("%s\n", token);
		token = my_strtok(new_str, " \t");
	}
	return (0);
}
