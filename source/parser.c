/*
** parser.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 18:05:35 2016 Quentin Bazin
** Last update Wed Mar 30 18:05:35 2016 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include <unistd.h>
#include "application.h"

/* t_err		parser_parse_str(t_parser	*parser, */
/* 				 t_application	*app, */
/* 				 char		*str) */
/* { */
/*   char		**commands; */
/*   int		error; */
/*   int		i; */
/*  */
/*   i = 0; */
/*   error = 0; */
/*   commands = my_str_to_array(str, ";"); */
/*   while (!error && commands[i]) */
/*     { */
/*       error = parser_add_command(parser, app, commands[i]); */
/*       ++i; */
/*     } */
/*   my_free_str_array(commands); */
/*   return (error); */
/* } */
/*  */
/* t_err		parser_add_pipe(t_parser	*parser, */
/* 				t_application	*app, */
/* 				char		*cmd) */
/* { */
/*   t_command	*current; */
/*   t_err		error; */
/*   char		**array; */
/*   int		i; */
/*  */
/*   if (!(array = my_strspl(cmd, true, '|'))) */
/*     return (print_error(ERROR_MALLOC_FAILED)); */
/*   if ((error = parser_add_command(parser, app, array[0]))) */
/*     return (error); */
/*   current = parser->last; */
/*   i = 0; */
/*   while (array[++i]) */
/*     { */
/*       if (current->output) */
/* 	return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT)); */
/*       if (!(current->piped_command = parser_new_command(array[i]))) */
/* 	return (print_error(ERROR_MALLOC_FAILED)); */
/*       if ((error = command_setup_pipe(current)) || */
/* 	  (error = command_parse_redirections(current->piped_command))) */
/* 	return (error); */
/*       current = current->piped_command; */
/*     } */
/*   my_free_str_array(array); */
/*   return (0); */
/* } */
/*  */
/* t_err		parser_add_command(t_parser		*parser, */
/* 				   t_application	*app, */
/* 				   char			*cmd) */
/* { */
/*   t_command	*command; */
/*   t_err		error; */
/*  */
/*   if (my_strchr(cmd, '|')) */
/*     return (parser_add_pipe(parser, app, cmd)); */
/*   if (!(command = parser_new_command(cmd))) */
/*     return (print_error(ERROR_MALLOC_FAILED)); */
/*   if ((error = command_parse_redirections(command))) */
/*     { */
/*       command_free(command); */
/*       return (error); */
/*     } */
/*   if (!parser->last && !parser->commands) */
/*     parser->last = parser->commands = command; */
/*   else */
/*     { */
/*       parser->last->next = command; */
/*       parser->last = command; */
/*     } */
/*   return (0); */
/* } */
/*  */
/* char	*parser_edit_command_str(char *cmd) */
/* { */
/*   char	*new; */
/*   int	new_length; */
/*   int	i; */
/*   int	j; */
/*  */
/*   new_length = my_strlen(cmd) + 1; */
/*   new_length += my_strcnt(cmd, '>') * 2 + my_strcnt(cmd, '<') * 2; */
/*   if (!(new = malloc(new_length))) */
/*     return (NULL); */
/*   i = 0; */
/*   j = 0; */
/*   while (cmd[i]) */
/*     { */
/*       if (i > 0 && (cmd[i - 1] == '>' || cmd[i - 1] == '<') */
/* 	  && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<') */
/* 	new[j++] = ' '; */
/*       new[j] = cmd[i]; */
/*       if ((cmd[i + 1] == '>' || cmd[i + 1] == '<') */
/* 	  && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<') */
/* 	new[++j] = ' '; */
/*       ++i; */
/*       ++j; */
/*     } */
/*   new[j] = '\0'; */
/*   return (new); */
/* } */
/*  */

t_command	*parser_add_command(t_parser *parser)
{
  t_command	*command;

  if (!(command = command_new()))
    return (NULL);
  if (parser->command)
    parser->command->next = command;
  parser->command = command;
  if (!parser->full_command)
    parser->full_command = command;
  return (command);
}

/* t_err		parser_init(t_parser *parser) */
/* { */
/*   if (!(parser->full_command = parser_new_expression())) */
/*     return (print_error(ERROR_MALLOC_FAILED)); */
/*   return (0); */
/* } */

void		parser_skip_whitespaces(t_parser *parser)
{
  if (parser->current && parser->current->token.type == TOKEN_WHITESPACE)
    parser->current = parser->current->next;
}

/* t_err		parser_expect_char(t_parser *parser, char c, */
/* 				   bool no_err, bool skip_whitespaces) */
/* { */
/*   t_token	*token; */
/*   t_err		error; */
/*  */
/*   if (!parser->current) */
/*     { */
/*       error = no_err ? -ERROR_UNEXPECTED_EOS : ERROR_UNEXPECTED_EOS; */
/*       return (print_error(error)); */
/*     } */
/*   if (skip_whitespaces) */
/*     parser_skip_whitespaces(parser); */
/*   if ((token = &parser->current->token) && */
/*       ((token->type == TOKEN_OPERATOR && c == token->value.operator) || */
/*        (token->type == TOKEN_WHITESPACE && c == ' '))) */
/*     { */
/*       parser->current = parser->current->next; */
/*       if (skip_whitespaces) */
/* 	parser_skip_whitespaces(parser); */
/*       return (0); */
/*     } */
/*   #<{(| error = no_err ? -ERROR_EXPECTED_CHAR : ERROR_EXPECTED_CHAR; |)}># */
/*   return (print_error(error, c, token->begin)); */
/* } */

t_err		parser_expect_operator(t_parser *parser, t_operator operator,
				       bool error_enabled)
{
  t_token	*token;
  /* t_err		error; */

  (void)error_enabled; /* FIXME */
  if (!parser->current)
    {
      /* error = error_enabled ? ERROR_UNEXPECTED_EOS : -ERROR_UNEXPECTED_EOS; */
      /* return (print_error(error)); */
      return (1);
    }
  parser_skip_whitespaces(parser);
  token = &parser->current->token;
  if ((token->type == TOKEN_REDIRECTION || token->type == TOKEN_SEPARATOR)
      && token->value.operator == operator)
    {
      parser->current = parser->current->next;
      parser_skip_whitespaces(parser);
      return (0);
    }
  /* error = error_enabled ? ERROR_EXPECTED_OPERATOR : -ERROR_EXPECTED_OPERATOR; */
  /* return (print_error(error, operator, token->begin)); */
  return (1);
}

/* void		parser_free_command(t_command *cmd) */
/* { */
/*   t_command	*tmp; */
/*   t_command	*next; */
/*  */
/*   tmp = cmd; */
/*   while (tmp) */
/*     { */
/*       parser_free_command(tmp->piped_command); */
/*       next = tmp->next; */
/*       free(tmp); */
/*       tmp = next; */
/*     } */
/* } */

#include "token.h"

t_err	parse_command(t_parser *parser, t_operator operator);

t_err	parse_redirection(t_parser *parser)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      if (!parser_expect_operator(parser, i, false))
	{
	  /* FIXME: Parse redirection here */
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
  while (i < 4)
    {
      if (i + 4 == OP_PIPE && !parser_expect_operator(parser, OP_PIPE, false))
	{}
      else if (!parser_expect_operator(parser, i + 4, false))
	return (parse_command(parser, i + 4));
      /* FIXME: Add 'Invalid null command' error */
      ++i;
    }
  return (0);
}

t_err		parse_command(t_parser *parser, t_operator operator)
{
  t_command	*command;

  (void)operator; /* FIXME */
  if (!parser->current || parser->current->token.type != TOKEN_NAME)
    return (0);
  if (!(command = parser_add_command(parser)))
    return (print_error(ERROR_MALLOC_FAILED));
  if (operator == OP_AND || operator == OP_OR)
    command->condition = (operator == OP_AND) ? CONDITION_AND : CONDITION_OR;
  else
    command->condition = CONDITION_NONE;
  while (parser->current && (parser->current->token.type == TOKEN_NAME ||
			     parser->current->token.type == TOKEN_WHITESPACE))
    {
      if (parser->current->token.type == TOKEN_NAME)
	command_add_argument(command, parser->current->token.content);
      parser->current = parser->current->next;
    }
  return (parse_separator(parser));
}

t_err		parse(t_parser *parser)
{
  t_err		error;

  while (!parser_expect_operator(parser, OP_SEMICOLON, false));
  if ((error = parse_command(parser, OP_SEMICOLON)))
    return (error);
  if (!parser_expect_operator(parser, OP_SEMICOLON, false))
    return (parse(parser));
  return (0);
}
