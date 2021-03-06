/*
** lexer_match.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:47:02 2016 Quentin Bazin
** Last update Sun Jun  5 15:34:36 2016 Nicolas Zimmermann
*/

#include <ctype.h>
#include <my.h>
#include <string.h>
#include "lexer.h"

t_match		lexer_match_separator(t_string_reader *reader, size_t pos)
{
  char		*operators[OP_COUNT];
  t_token_value	value;
  int		i;

  i = 0;
  operators[0] = "&&";
  operators[1] = "||";
  operators[2] = "|";
  operators[3] = ";";
  while (i < 4)
    {
      if (my_strstr(reader->string + pos, operators[i]) == reader->string + pos)
	{
	  pos += my_strlen(operators[i]);
	  value.operator = i + 4;
	  return (gen_match_from_token(reader, pos, TOKEN_SEPARATOR, value));
	}
      ++i;
    }
  return (lexer_gen_empty_match());
}

t_match		lexer_match_redirection(t_string_reader *reader, size_t pos)
{
  char		*operators[OP_COUNT];
  t_token_value	value;
  int		i;

  i = 0;
  operators[0] = "<<";
  operators[1] = ">>";
  operators[2] = "<";
  operators[3] = ">";
  while (i < 4)
    {
      if (my_strstr(reader->string + pos, operators[i]) == reader->string + pos)
	{
	  pos += my_strlen(operators[i]);
	  value.operator = i;
	  return (gen_match_from_token(reader, pos, TOKEN_REDIRECTION, value));
	}
      ++i;
    }
  return (lexer_gen_empty_match());
}

t_match		lexer_match_name(t_string_reader *reader, size_t pos)
{
  t_token_value	token_value;
  t_match	match;
  size_t	reader_pos;

  if (!reader->string[pos] ||
      !lexer_is_name(reader->string[pos],
		     (pos > 0) ? reader->string[pos - 1] : 0,
		     reader->string[pos + 1]))
    return (lexer_gen_empty_match());
  pos++;
  while (reader->string[pos] &&
	 lexer_is_name(reader->string[pos],
		       (pos > 0) ? reader->string[pos - 1] : 0,
		       reader->string[pos + 1]))
    pos++;
  reader_pos = reader->pos;
  my_memset(&token_value, 0, sizeof(t_token_value));
  match = gen_match_from_token(reader, pos, TOKEN_NAME, token_value);
  match.token.value.string = clear_name(my_strndup(reader->string + reader_pos,
                                                   pos - reader_pos));
  return (match);
}

t_match		lexer_match_whitespace(t_string_reader *reader, size_t pos)
{
  t_token_value	token_value;

  if (!lexer_is_whitespace(reader->string[pos]))
    return (lexer_gen_empty_match());
  while (lexer_is_whitespace(reader->string[pos]))
    ++pos;
  my_memset(&token_value, 0, sizeof(t_token_value));
  return (gen_match_from_token(reader, pos, TOKEN_WHITESPACE, token_value));
}

t_match		lexer_match(t_string_reader *reader)
{
  t_match_func	functions[TOKEN_COUNT];
  t_match	match;
  int		i;

  i = 0;
  functions[0] = &lexer_match_whitespace;
  functions[1] = &lexer_match_separator;
  functions[2] = &lexer_match_redirection;
  functions[3] = &lexer_match_string;
  functions[4] = &lexer_match_name;
  while (i < TOKEN_COUNT)
    {
      match = functions[i](reader, reader->pos);
      if (match.type == MATCH_TOKEN || match.type == MATCH_ERROR)
	return (match);
      ++i;
    }
  return (lexer_gen_empty_match());
}
