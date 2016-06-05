/*
** parser.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 18:05:25 2016 Quentin Bazin
** Last update Sun Jun  5 11:22:44 2016 Nicolas Zimmermann
*/
#ifndef PARSER_H_
# define PARSER_H_

# include <stdbool.h>
# include "command.h"
# include "error.h"
# include "token.h"

typedef struct		s_parser
{
  t_token_elem		*list;
  t_token_elem		*current;
  t_command		*full_command;
  t_command		*command;
}			t_parser;

/* parser.c */
t_command	*parser_add_command(t_parser *parser, bool is_piped);
void		parser_skip_whitespaces(t_parser *parser);
t_err		parser_expect_operator(t_parser *parser, t_operator operator,
				       bool error_enabled);

t_err		parse(t_parser *parser);
t_err		parse_command(t_parser *parser, t_operator, bool expected);
t_err           parse_arguments(t_parser *parser, t_command *command);
t_err           parse_redirection(t_parser *parser);

#endif /* !PARSER_H_ */
