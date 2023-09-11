#include "shell.h"

char *get_path(char *cmd)
{
	char *path, *path_cpy;
	int cmd_len;/*get command length*/
	char *token_path;
	int token_len;
	char *full_path;
	struct stat exist;/*check if a file exists, file status*/

	/*GET THE ENVIRONMENT PATH*/
	path = getenv("PATH");

	if (path)
	{
		/*CREATE A COPY OF THE PATH*/
		path_cpy = strdup(path);
		
		/*get command length*/
		cmd_len = strlen(cmd);

		/*break down path into tokens with delimiter :*/
		token_path = strtok(path_cpy, ":");

		while (token_path)
		{
			token_len = strlen(token_path);
			full_path = malloc(cmd_len + token_len + 2);/*one for / and NULL*/
			/*copy token obtained into the fullpath*/
			strcpy(full_path, token_path);
			strcat(full_path, "/");
			strcat(full_path, cmd);
			strcat(full_path, "\0");
		       
			/*check if directory exists*/
			if (stat(full_path, &exist) == 0)
			{
				/*path exists*/

				/*free the copied path*/
				free(path_cpy);

				/*return the full path*/
				return (full_path);
			}
			else
			{
				/*free up the full path*/
				free(full_path);
				token_path = strtok(NULL, ":");
			}
		}

		/*free up path if not exists*/
		free(path_cpy);

		/*check if the command itself is valid*/
		if (stat(cmd, &exist) == 0)
			return (cmd);
	}
		return (NULL);
}
