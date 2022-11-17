#ifndef SCANNER_H
#define SCANNER_H

struct token_s
{
	struct source_s *src; /* src input */
	int text_len; /* text length */
	char *text; /* token */
};

extern struct token_s eof_token; /* EOF token */

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

#endif
