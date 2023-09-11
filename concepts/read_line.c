#include "shell.h"

/**
 * main - reads user input and print
 * Return: 0
 */

int main(void)
{
	char *prompt = "Prompt$ ";
	size_t line_len = 0;
	char *lines_buffer = NULL;
	ssize_t line_size = 0;
	char *lines_read;
	const char *delim = " \n";
	char **argv;
	int argc = 0, i = 0;

	while (1)
	{
		printf("%s", prompt);
		line_size = getline(&lines_buffer, &line_len, stdin);
		/*check if getline return -1 or EOF*/
		if (line_size == -1)
		{
			perror("\nExit getline...");
			return (-1);
		}
		/*allocate space for lines read*/
		lines_read = strdup(lines_buffer);

		argv = split_str(lines_read, delim);
		run_cmd(argv);
	}
	/*free the allocated space*/
	free(lines_buffer);
	free(lines_read);
	while (argv[i] != NULL)
		free(argv[i]);
	free(argv);

	return (0);
}
