/*
** lexer_utils.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun May 22 14:47:28 2016 Quentin Bazin
** Last update Sat Jun  4 21:59:03 2016 Nicolas Zimmermann
*/

#include <ctype.h>
#include <my.h>
#include <string.h>
#include "lexer.h"

bool	lexer_is_name(char c, char last_c)
{
  char	*reserved;
  int	i;

  i = 0;
  reserved = ";|<>&\t ";
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

t_match		lexer_gen_empty_match()
{
  t_match	match;

  my_memset(&match, 0, sizeof(t_match));
  match.type = MATCH_NONE;
  return (match);
}

t_match		gen_match_from_token(t_string_reader	*reader,
				     size_t		end,
				     t_token_type	type,
				     t_token_value	value)
{
  t_match	match;

  match.type = MATCH_TOKEN;
  match.token.type = type;
  match.token.value = value;
  match.token.begin = reader->pos;
  match.token.end = end;
  match.token.content = my_strndup(reader->string + reader->pos,
				   end - reader->pos);
  reader->pos = end;
  return (match);
}
