/*
** lexer_match_string.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Sun Jun  5 08:13:43 2016 Nicolas Zimmermann
** Last update Sun Jun  5 15:46:08 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "lexer.h"

t_match		lexer_match_string(t_string_reader *reader, size_t pos)
{
  t_token_value	token_value;
  t_match	match;
  char		c;
  size_t	reader_pos;

  if (reader->string[pos] != '\"' && reader->string[pos] != '\'')
    return (lexer_gen_empty_match());
  c = reader->string[pos];
  while ((reader->string[++pos] &&
	  (reader->string[pos] != '\"' && reader->string[pos] != '\'')) ||
	 count_backslash(reader->string, pos) % 2 == 1);
  if (!reader->string[pos] || reader->string[pos] != c)
    return (lexer_gen_error_match());
  my_memset(&token_value, 0, sizeof(t_token_value));
  pos += 1;
  reader_pos = reader->pos;
  match = gen_match_from_token(reader, pos, TOKEN_STRING, token_value);
  match.token.value.string = clear_name(my_strndup(reader->string + reader_pos
						   + 1, pos - reader_pos - 3));
  return (match);
}
