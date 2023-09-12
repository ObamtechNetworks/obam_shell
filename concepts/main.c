#include "shell.h"

/**
 * main - reads user input and print
 * Return: 0
 */

int main(void)
{
	const char *delim = " \n";
	char **argv;
	int i = 0;
	char *user_input;
	char *lines_read;

	pid_t child;
	int status;
	while (1)
	{
		/*call the prompt function*/
		user_input = prompt();

		/*split inputs into arguments*/
		argv = split_str(user_input, delim);
		if (argv == NULL)
		{
			free(user_input);
			i = 0;
			while (argv[i] != NULL)
			{
				free(argv[i]);
				i++;
			}
			return (-1);
		}
		/*create child process*/
		child = fork();
		/*check return value*/
		if (child == -1)
		{
			perror("process failed");
			return (-1);
		}

		if (child == 0)
			run_cmd(argv);
		else
		{
			wait(&status);
		}
	}
	/*free the allocated space*/
	free(user_input);
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (0);
}
