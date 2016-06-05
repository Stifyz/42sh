/*
** parser_arguments.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Sun Jun  5 10:39:01 2016 Nicolas Zimmermann
** Last update Sun Jun  5 16:00:58 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "parser.h"

char	*parser_concat(t_parser *parser)
{
  char	*tmp;

  tmp = NULL;
  while (parser->current &&
	 (parser->current->token.type == TOKEN_NAME ||
          parser->current->token.type == TOKEN_STRING))
    {
      if (!(tmp = my_strcatm(tmp, parser->current->token.value.string)))
	return (NULL);
      parser->current = parser->current->next;
    }
  return (tmp);
}

t_err           parse_arguments(t_parser *parser, t_command *command)
{
  t_err         error;
  char          *tmp;
  bool		b;

  while (parser->current && (parser->current->token.type == TOKEN_NAME ||
                             parser->current->token.type == TOKEN_WHITESPACE ||
                             parser->current->token.type == TOKEN_REDIRECTION ||
                             parser->current->token.type == TOKEN_STRING))
    {
      b = true;
      if (parser->current->token.type == TOKEN_NAME ||
          parser->current->token.type == TOKEN_STRING)
        {
          if (!(tmp = parser_concat(parser)))
            return (print_error(ERROR_MALLOC_FAILED));
          if ((error = command_add_argument(command, tmp)))
            return (error);
	  b = false;
	}
      else if (parser->current->token.type == TOKEN_REDIRECTION)
	if ((error = parse_redirection(parser)))
	  return (error);
      (b) ? parser->current = parser->current->next : 0;
    }
  return (0);
}
