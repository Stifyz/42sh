/*
** builtins.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Sat Mar 26 10:31:46 2016 Quentin Bazin
** Last update Sat Jun  4 03:26:05 2016 Bouama_r
*/
#ifndef BUILTINS_H_
# define BUILTINS_H_

# include "error.h"

# define BUILTINS_COUNT 7

struct s_application;

typedef struct	s_builtin
{
  char		*name;
  t_err		(*func)(struct s_application *, int, char **);
}		t_builtin;

void	builtin_init_array(struct s_application *app);
int	builtin_run(struct s_application *app, char **argv);
int	builtin_get_id(struct s_application *app, char *name);

t_err	builtin_cd(struct s_application *app, int argc, char **argv);
t_err	builtin_setenv(struct s_application *app, int argc, char **argv);
t_err	builtin_unsetenv(struct s_application *app, int argc, char **argv);
t_err	builtin_env(struct s_application *app, int argc, char **argv);
t_err	builtin_exit(struct s_application *app, int argc, char **argv);

#endif /* !BUILTINS_H_ */
