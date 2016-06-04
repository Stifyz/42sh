/*
** parser_command.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Jun 04 18:22:34 2016 Quentin Bazin
** Last update Sat Jun 04 18:22:34 2016 Quentin Bazin
*/

#include "parser.h"

t_err		parse_redirection(t_parser *parser)
{
  t_io_mode	mode;
  char		*token_content;
  int		i;

  i = 0;
  while (i < 4)
    {
      if (!parser_expect_operator(parser, i, false))
	{
	  mode = (i % 2 == 0) ? IO_MODE_INPUT : IO_MODE_OUTPUT;
	  mode |= (i < 2) ? IO_MODE_DOUBLE : IO_MODE_SIMPLE;
	  /* FIXME: Missing name for redirect. */
	  if ((mode & IO_MODE_INPUT) && (parser->command->input || parser->command->input_fd != 0))
	    return (print_error(ERROR_AMBIGUOUS_INPUT_REDIRECT));
	  if ((mode & IO_MODE_OUTPUT) && (parser->command->output || parser->command->output_fd != 1))
	    return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT));
	  parser_skip_whitespaces(parser);
	  if (!parser->current ||
	      parser->current->token.type != TOKEN_NAME)
	    return (print_error(ERROR_MISSING_NAME_FOR_REDIRECT));
	  token_content = parser->current->token.content;
	  if (((mode & IO_MODE_INPUT) &&
	       !(parser->command->input = redirection_new(token_content, mode)))
	      || ((mode & IO_MODE_OUTPUT) &&
		  !(parser->command->output = redirection_new(token_content,
							      mode))))
	    return (print_error(ERROR_MALLOC_FAILED));
	  return (0);
	}
      ++i;
    }
  return (0);
}

t_err	parse_separator(t_parser *parser)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      if (!parser_expect_operator(parser, i + 4, false))
	{
	  if (i + 4 == OP_PIPE && parser->command->output)
	    return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT));
	  return (parse_command(parser, i + 4, true));
	}
      ++i;
    }
  return (0);
}

t_err		parse_arguments(t_parser *parser, t_command *command)
{
  t_err		error;

  while (parser->current && (parser->current->token.type == TOKEN_NAME ||
			     parser->current->token.type == TOKEN_WHITESPACE ||
			     parser->current->token.type == TOKEN_REDIRECTION))
    {
      if (parser->current->token.type == TOKEN_NAME)
	error = command_add_argument(command, parser->current->token.content);
      else if (parser->current->token.type == TOKEN_REDIRECTION)
	error = parse_redirection(parser);
      if (error)
	return (error);
      parser->current = parser->current->next;
    }
  return (0);
}

t_err		parse_command(t_parser *parser, t_operator operator,
			      bool expected)
{
  t_command	*command;
  t_err		error;

  if (!parser->current || (parser->current->token.type != TOKEN_NAME &&
			   parser->current->token.type != TOKEN_REDIRECTION))
    return ((expected) ? print_error(ERROR_INVALID_NULL_COMMAND) : 0);
  if (!(command = parser_add_command(parser, operator == OP_PIPE)))
    return (print_error(ERROR_MALLOC_FAILED));
  if (operator == OP_AND || operator == OP_OR)
    command->condition = (operator == OP_AND) ? CONDITION_AND : CONDITION_OR;
  else
    command->condition = CONDITION_NONE;
  if ((error = parse_arguments(parser, command)))
    return (error);
  if (!command->args)
    return ((expected || command->input || command->output) ?
	    print_error(ERROR_INVALID_NULL_COMMAND) : 0);
  return (parse_separator(parser));
}

t_err		parse(t_parser *parser)
{
  t_err		error;

  while (!parser_expect_operator(parser, OP_SEMICOLON, false));
  if (!parser->current)
    return (0);
  if ((error = parse_command(parser, OP_SEMICOLON, false)))
    return (error);
  if (!parser_expect_operator(parser, OP_SEMICOLON, false))
    return (parse(parser));
  return (0);
}
