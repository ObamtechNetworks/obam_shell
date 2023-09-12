#include "shell.h"

/**
 * main - test codes
 * Return: 0 (Success)
 */

int main(void)
{
	char word[] = "I want to break and test this string";
	char *delim = " ";
	int i;

	char **tokens = split_str(word, delim);

	/*if tokens == NULL*/
	if (tokens == NULL)
	{
		perror("memory alloc failed");
		return (-1);
	}

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]);
		i++;
	}

	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);

	return (0);
}
