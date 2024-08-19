#include "main.h"

/**
* main - entry point of the program.
*
* Return: 0 on sucess.
*/
int main(void)
{
	char str[] = "This is a test string";
	char **words;
	int i;

	words = split_string(str);

	for (i = 0; words[i] != NULL; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);

	return (0);
}
