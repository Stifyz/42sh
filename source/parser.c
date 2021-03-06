/*
** parser.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 18:05:35 2016 Quentin Bazin
** Last update Wed Mar 30 18:05:35 2016 Quentin Bazin
*/

#include "parser.h"

t_command	*parser_add_command(t_parser *parser, bool is_piped)
{
  t_command	*command;

  if (!(command = command_new()))
    return (NULL);
  if (parser->command)
    {
      if (!is_piped)
	{
	  while (parser->command->piped_parent)
	    parser->command = parser->command->piped_parent;
	  parser->command->next = command;
	}
      else
	{
	  parser->command->piped_command = command;
	  command_init_pipe(parser->command);
	}
    }
  parser->command = command;
  if (!parser->full_command)
    parser->full_command = command;
  return (command);
}

void		parser_skip_whitespaces(t_parser *parser)
{
  if (parser->current && parser->current->token.type == TOKEN_WHITESPACE)
    parser->current = parser->current->next;
}

bool		parser_expect_operator(t_parser *parser, t_operator operator)
{
  t_token	*token;

  if (!parser->current)
    return (1);
  parser_skip_whitespaces(parser);
  token = &parser->current->token;
  if (token
      && (token->type == TOKEN_REDIRECTION || token->type == TOKEN_SEPARATOR)
      && token->value.operator == operator)
    {
      parser->current = parser->current->next;
      parser_skip_whitespaces(parser);
      return (0);
    }
  return (1);
}

t_err		parse(t_parser *parser)
{
  t_err		error;

  while (!parser_expect_operator(parser, OP_SEMICOLON));
  if (!parser->current)
    return (0);
  if ((error = parse_command(parser, OP_SEMICOLON, false)))
    return (error);
  if (!parser_expect_operator(parser, OP_SEMICOLON))
    return (parse(parser));
  if (parser->current && parser->current->token.type == TOKEN_SEPARATOR
      && (parser->current->token.value.operator == OP_PIPE ||
	  parser->current->token.value.operator == OP_OR))
    return (print_error(ERROR_INVALID_NULL_COMMAND));
  return (0);
}
