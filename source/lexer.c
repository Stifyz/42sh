/*
** lexer.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:44:57 2016 Quentin Bazin
** Last update Sun Jun  5 09:58:36 2016 Nicolas Zimmermann
*/

#include "lexer.h"

bool	lexer_is_name(char c, char last_c, char next_c)
{
  char	*reserved;
  int	i;

  i = 0;
  reserved = ";|<>&\t \"\'";
  if (c == '\\')
    if (!next_c && last_c != '\\')
      return (false);
  if (!c)
    return (false);
  while (reserved[i])
    if (c == reserved[i++] && last_c != '\\')
      return (false);
  return (true);
}

bool	lexer_is_whitespace(char c)
{
  return (c == ' ' || c == '\t');
}

t_err	lexer_fill_token_list(t_string_reader *reader, t_token_list *list)
{
  t_match	match;
  t_err		error;

  while (reader->pos < reader->length)
    {
      match = lexer_match(reader);
      if (match.type == MATCH_NONE)
	return (print_error(ERROR_UNEXPECTED_CHAR, reader->pos));
      else if (match.type == MATCH_ERROR)
	return (print_error(ERROR_SYNTAX_ERROR, reader->pos));
      else if (match.type == MATCH_TOKEN
	       && (error = token_list_add(list, &match.token)))
	return (print_error(ERROR_TOKEN_LIST_ADD_FAILED));
    }
  return (0);
}
