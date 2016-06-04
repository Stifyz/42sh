/*
** parser.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 18:05:25 2016 Quentin Bazin
** Last update Wed Mar 30 18:05:25 2016 Quentin Bazin
*/
#ifndef PARSER_H_
# define PARSER_H_

# include <stdbool.h>
# include "command.h"
# include "error.h"
# include "token.h"

/* typedef enum		e_expr_type */
/* { */
/*   EXPR_TYPE, */
/*   EXPR_NAME, */
/*   EXPR_VAR_DECL, */
/*   EXPR_FUNC_DECL, */
/*   EXPR_FUNC_PTR_NAME, */
/*   EXPR_FUNC_PTR_DECL */
/* }			t_expr_type; */
/*  */
/* typedef struct		s_expression */
/* { */
/*   t_ctype		ctype; */
/*   t_expr_type		type; */
/*   int			pointer_count; */
/*   char			*type_name; */
/*   char			*name; */
/*   struct s_expression	*child; */
/*   struct s_expression	*next; */
/* }			t_expression; */

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

#endif /* !PARSER_H_ */
