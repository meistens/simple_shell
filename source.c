#include <errno.h>
#include "shell.h"
#include "source.h"

/**
 * unget_char - returns last char retrieved from input back to src
 *
 */

void unget_char(struct source_s *src)
{
	if (src->pos < 0)
		return;
	src->pos--;
}

/**
 * next_char - returns the next char of input
 * Return: the following input char or EOF if none
 *
 */

char next_char(struct source_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return ERRCHAR;
	}

	char i = 0;
	if (src->pos == INIT_SRC_POS)
	{
		src->pos = -1;
	}
	else
	{
		i = src->buffer[src->pos];
	}

	if (++src->pos >= src->bufsize)
	{
		src->pos = src->bufsize;
		return EOF;
	}

	return src->buffer[src->pos];
}

/**
 * peek_char - looks at the next input at src
 * Return: poaition of input at buffer
 *
 */

char peek_char(struct source_s *src)
{
	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return ERRCHAR;
	}

	long ppos = src->pos;

	if (ppos == INIT_SRC_POS)
		ppos++;
	ppos++;

	if (ppos >= src->bufsize)
		return EOF;
	return src->buffer[ppos];
}

/**
 * skip_whitespace - skips all whitespaces
 * Return: next char
 *
 */

void skip_whitespace(struct source_s *src)
{
	char c;

	if (!src || !src->buffer)
		return;

	while ((c = peek_char(src)) != EOF && (c == '\t'))
		next_char(src);

}
