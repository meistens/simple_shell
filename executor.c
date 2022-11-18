#include "main.h"

void execmd(char **argv)
{
	char *command = NULL,
		*cmd = NULL;

	if (argv)
	{
		command = argv[0];

		cmd = get_location(command);

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("error:");
		}
	}
}
