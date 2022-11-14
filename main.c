/**
 * description: basic REPL file
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "shell.h"

int main(int argc, char **argv)
{
	char *cmd;

	do {
		/* prompt str and read cmd functions */
		prompt1();
		cmd = read_cmd();

		/* check for command errors and exit REPL */
		if (!cmd)
		{
			exit(EXIT_SUCCESS);
		}

		/* if str matches new line (empty command) */
		/* free memory and continue with the loop */
		if (cmd[0] == '\0' || strcmp(cmd, "\n") == 0)
		{
			free(cmd);
			continue;
		}

		/* if str command matches exit, free memory */
		/* and exit REPL loop */
		if (strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}

		/* else print the output of the command */
		/* and free memory for next command */
		printf("%s\n", cmd);
		free(cmd);
	} while (1);
	exit(EXIT_SUCCESS);
}

/**
 * read_cmd - user command input(s)
 *
 * Return: pointer
 */

char *read_cmd(void)
{
	/* create a buffer to store inputs in 1024 bytes */
	/* pointer to NULL or end of address */
	/* pointer length to zero */
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	/* while loop to get command string from stream/stdin in 1024 bytes */
	while (fgets(buf, 1024, stdin))
	{
		/* assign strlen to buffer, if there is an input */
		/* i.e ptr is not empty, create a buffer */
		/* else reallocate memory to another ptr */
		int buflen = strlen(buf);

		if (!ptr)
		{
			ptr = malloc(buflen + 1);
		}
		else
		{
			char *ptr2 = realloc(ptr, ptrlen + buflen + 1);
			/* copy buffer(ptr) with user input */
			if (ptr2)
			{
				ptr = ptr2;
			}
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}

		/* if error allocating buffers, print err and return NULL */
		if (!ptr)
		{
			fprintf(stderr, "err: buf err: %s\n", strerror(errno));
			return (NULL);
		}

		/* using strcpy (check man page)*/
		strcpy(ptr + ptrlen, buf);

		/* if input ends in a newline */
		/* if not escaped, input line is complete */
		/* else remove the '//' and newline, print prompt2 sym */
		if (buf[buflen - 1] == '\n')
		{
			if (buflen == 1 || buf[buflen - 2] != '\\')
				return (ptr);

			ptr[ptrlen + buflen - 2] = '\0';
			buflen -= 2;
			prompt2();
		}

		ptrlen += buflen;
	}
	return (ptr);
}
