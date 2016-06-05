/*
** application.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Fri Mar 25 16:57:25 2016 Quentin Bazin
** Last update Sun Jun  5 14:49:54 2016 Nicolas Zimmermann
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
  t_builtin	builtins[BUILTINS_COUNT];
  t_alias	*alias_list;
}		t_application;

t_application	*gl_app;

t_err		application_init(t_application *app, char **env);
void		application_run(t_application *app);
void		application_parse(t_application *app, t_token_list *token_list);
void		application_run_command(t_application *app, char *cmd);
void		application_free(t_application *app);

#endif /* !APPLICATION_H_ */
