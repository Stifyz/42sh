/*
** lexer.h for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:43:42 2016 Quentin Bazin
** Last update Sat Jun  4 18:23:11 2016 Nicolas Zimmermann
*/
#ifndef LEXER_H_
# define LEXER_H_

# include <stdbool.h>
# include "token.h"

typedef struct	s_string_reader
{
  char		*string;
  size_t	length;
  size_t	pos;
}		t_string_reader;

typedef enum	e_match_type
{
  MATCH_NONE,
  MATCH_TOKEN,
  MATCH_ERROR
}		t_match_type;

typedef struct	s_match
{
  t_match_type	type;
  t_token	token;
}		t_match;

typedef t_match (*t_match_func)(t_string_reader *, size_t);

/* lexer.c */
t_err		lexer_fill_token_list(t_string_reader *reader, t_token_list *);

/* lexer_match.c */
t_match		lexer_match(t_string_reader *reader);

/* lexer_utils.c */
bool		lexer_is_name(char c, char last_c);
bool		lexer_is_whitespace(char c);
t_match		lexer_gen_empty_match();
t_match		gen_match_from_token(t_string_reader	*reader,
				     size_t		end,
				     t_token_type	type,
				     t_token_value	value);

#endif /* !LEXER_H_ */
