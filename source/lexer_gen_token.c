/*
** lexer_gen_token.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Sun Jun  5 12:12:17 2016 Nicolas Zimmermann
** Last update Sun Jun  5 15:59:14 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "lexer.h"

t_match         lexer_gen_empty_match()
{
  t_match       match;

  my_memset(&match, 0, sizeof(t_match));
  match.type = MATCH_NONE;
  return (match);
}

t_match         lexer_gen_error_match()
{
  t_match       match;

  my_memset(&match, 0, sizeof(t_match));
  match.type = MATCH_ERROR;
  return (match);
}

t_match         gen_match_from_token(t_string_reader    *reader,
                                     size_t             end,
                                     t_token_type       type,
                                     t_token_value      value)
{
  t_match       match;

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
