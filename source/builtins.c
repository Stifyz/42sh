/*
** builtins.c for  in /blinux_home/bazin_q/rendu/PSU/PSU_2015_minishell1/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Jan 21 10:20:57 2016 Quentin Bazin
** Last update Thu Jan 21 10:20:57 2016 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include "application.h"

void	builtin_init_array(t_application *app)
{
  app->builtins[0].name = "cd";
  app->builtins[1].name = "setenv";
  app->builtins[2].name = "unsetenv";
  app->builtins[3].name = "env";
  app->builtins[4].name = "exit";
  app->builtins[0].func = &builtin_cd;
  app->builtins[1].func = &builtin_setenv;
  app->builtins[2].func = &builtin_unsetenv;
  app->builtins[3].func = &builtin_env;
  app->builtins[4].func = &builtin_exit;
}

int	builtin_run(t_application *app, char **argv)
{
  int	id;
  int	argc;

  if ((id = builtin_get_id(app, argv[0])) != -1)
    {
      argc = 0;
      while (argv[argc] != NULL)
	++argc;
      if (app->builtins[id].func(app, argc, argv))
	app->exit_code = 1;
      return (1);
    }
  return (0);
}

int	builtin_get_id(t_application *app, char *name)
{
  int	i;

  i = 0;
  while (i < BUILTINS_COUNT)
    {
      if (my_strcmp(name, app->builtins[i].name) == 0)
	return (i);
      ++i;
    }
  return (-1);
}

t_err	builtin_exit(t_application *app, int argc, char **argv)
{
  if (argc > 2)
    return (print_error(ERROR_TOO_MANY_ARGUMENTS, "exit"));
  if (argc == 2)
    {
      if (!my_str_isnum(argv[1]))
	return (print_error(ERROR_POSITIVE_INTEGER_REQUIRED, "exit"));
      app->exit_code = my_getnbr(argv[1]);
    }
  app->is_running = false;
  /* my_putstr("exit\n"); */
  return (0);
}
