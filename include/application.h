/*
** application.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Fri Mar 25 16:57:25 2016 Quentin Bazin
** Last update Sat Jun  4 06:19:22 2016 Bouama_r
*/
#ifndef APPLICATION_H_
# define APPLICATION_H_

# include <stdbool.h>
# include "builtins.h"
# include "env.h"
# include "parser.h"
# include "prompt.h"
# include "alias.h"

typedef struct	s_application
{
  t_env		*env;
  char		**path;
  char		*cd_history;
  int		exit_code;
  bool		is_running;
  t_prompt	prompt;
  t_parser	parser;
  t_builtin	builtins[BUILTINS_COUNT];
  t_alias	*alias_list;
}		t_application;

t_err		application_init(t_application *app, char **env);
void		application_run(t_application *app);
void		application_run_command(t_application *app, char *cmd);
void		application_free(t_application *app);

#endif /* !APPLICATION_H_ */
