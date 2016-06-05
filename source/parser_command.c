/*
** parser_command.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Jun 04 18:22:34 2016 Quentin Bazin
** Last update Sun Jun  5 11:21:13 2016 Nicolas Zimmermann
*/

#include "parser.h"

t_err		check_redirection(t_parser *parser, t_io_mode mode)
{
  if ((mode & IO_MODE_INPUT)
      && (parser->command->input || parser->command->input_fd != 0))
    return (print_error(ERROR_AMBIGUOUS_INPUT_REDIRECT));
  if ((mode & IO_MODE_OUTPUT)
      && (parser->command->output || parser->command->output_fd != 1))
    return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT));
  parser_skip_whitespaces(parser);
  if (!parser->current || parser->current->token.type != TOKEN_NAME)
    return (print_error(ERROR_MISSING_NAME_FOR_REDIRECT));
  return (0);
}

t_err		parse_redirection(t_parser *parser)
{
  t_io_mode	mode;
  t_err		error;
  char		*token_content;
  int		i;

  i = -1;
  while (++i < 4)
    if (!parser_expect_operator(parser, i))
      {
	mode = (i % 2 == 0) ? IO_MODE_INPUT : IO_MODE_OUTPUT;
	mode |= (i < 2) ? IO_MODE_DOUBLE : IO_MODE_SIMPLE;
	if ((error = check_redirection(parser, mode)))
	  return (error);
	token_content = parser->current->token.content;
	if (((mode & IO_MODE_INPUT) &&
	     !(parser->command->input = redirection_new(token_content, mode)))
	    || ((mode & IO_MODE_OUTPUT) &&
		!(parser->command->output = redirection_new(token_content,
							    mode))))
	  return (print_error(ERROR_MALLOC_FAILED));
	return (0);
      }
  return (0);
}

t_err	parse_separator(t_parser *parser)
{
  int	i;

  i = 0;
  while (i < 3)
    {
      if (!parser_expect_operator(parser, i + 4))
	{
	  if (i + 4 == OP_PIPE && parser->command->output)
	    return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT));
	  return (parse_command(parser, i + 4, true));
	}
      ++i;
    }
  return (0);
}

t_err		parse_command(t_parser *parser, t_operator operator,
			      bool expected)
{
  t_command	*command;
  t_err		error;

  if (!parser->current || (parser->current->token.type != TOKEN_NAME &&
			   parser->current->token.type != TOKEN_REDIRECTION &&
			   parser->current->token.type != TOKEN_STRING))
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
