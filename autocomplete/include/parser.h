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

# include "command.h"
# include "error.h"

typedef struct	s_parser
{
  t_command	*commands;
  t_command	*last;
}		t_parser;

t_err		parser_parse_str(t_parser *, struct s_application *, char *);
t_err		parser_add_pipe(t_parser *, struct s_application *, char *);
t_err		parser_add_command(t_parser *, struct s_application *, char *);
char		*parser_edit_command_str(char *cmd);
t_command	*parser_new_command(char *cmd);

#endif /* !PARSER_H_ */
