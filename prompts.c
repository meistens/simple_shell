/**
 * description: file contsins code responsible for the prompts in the shell
 * @prompt1: symbol indicating shell is awaiting a command
 * @prompt2: handles multiline commands
 *
 */

#include <stdio.h>
#include "shell.h"

void prompt1(void)
{
	fprintf(stderr, "$ ");
}

void prompt2(void)
{
	fprintf(stderr, "> ");
}
