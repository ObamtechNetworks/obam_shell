#include "shell.h"


void run_cmd(char **argv)
{
	char *cmd = NULL, *run_cmd = NULL;
	int rtn_val;

	if (argv)
	{
		/*set the first args command*/
		cmd = argv[0];

		/*generate the path to cmd*/
		run_cmd = get_path(cmd);

		/*call execve to run the command*/
		rtn_val = execve(run_cmd, argv, NULL);

		/*check for potential execve errors*/
		if (rtn_val == -1)
			perror("execve error");
	}
}
