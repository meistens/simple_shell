#ifndef SOURCE_H
#define SOURCE_H

#define EOF (-1)
#define ERRCHAR (0)
#define INIT_SRC_POS (-2)

/* abstract input str to make scanning easier */
struct source_s
{
	char *buffer; /* input text */
	long bufsize; /* size of the buffer */
	long pos /* absolute char position in source */
};

char next_char(struct source_s *src); /* scan char from input function */
char unget_char(struct soruce_s *src); /* return last char from input */
char peek_char(struct source_s *src); /* check next char only */
void skip_whitespace(struct source_s *src); /* skip whitespaces */

#endif
