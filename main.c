#include "main.h"

int main(int ac, char **argv)
{
	char *cursor = "(hsh) $";
	char *ptr = NULL,
		*ptr_cpy = NULL;
	size_t n = 0;
	ssize_t chars_read;
	const char *delimitter = " \n";
	int num_of_tokens = 0;
	char *token;
	int i;

	(void)ac;

	do
	{
		printf("%s", cursor);
		chars_read = getline(&ptr, &n, stdin);

		if (chars_read == -1)
		{
			printf("exiting shell \n");
			return (-1);
		}

		ptr_cpy = malloc(sizeof(char) * chars_read);
		if (ptr_cpy == NULL)
		{
			perror("err: memory alloc error");
			return (-1);
		}

		strcpy(ptr_cpy, ptr);

		token = strtok(ptr, delimitter);

		while (token != NULL)
		{
			num_of_tokens++;
			token = strtok(NULL, delimitter);
		}
		num_of_tokens++;

		argv = malloc(sizeof(char *) * num_of_tokens);

		token = strtok(ptr_cpy, delimitter);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i],token);
			token = strtok(NULL, delimitter);
		}
		argv[i] = NULL;
		execmd(argv);
	} while (1);

	free(ptr_cpy);
	free(ptr);
	return (0);
}
