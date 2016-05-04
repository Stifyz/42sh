/*
** builtin_cd.c for  in /blinux_home/bazin_q/rendu/PSU/PSU_2015_minishell1/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Jan 21 10:39:18 2016 Quentin Bazin
** Last update Thu Jan 21 10:39:18 2016 Quentin Bazin
*/

#include <limits.h>
#include <my.h>
#include <stdlib.h>
#include <unistd.h>
#include "application.h"

t_err	builtin_cd_change_dir(t_application *app, char *new_cwd)
{
  app->cd_history = my_strdup(my_getenv(app->env, "PWD"));
  if (chdir(new_cwd) == -1)
    return (print_error(ERROR_UNABLE_TO_OPEN_DIRECTORY, "cd", new_cwd));
  if ((new_cwd = malloc(PATH_MAX + 1)) == NULL)
    return (print_error(ERROR_MALLOC_FAILED));
  getcwd(new_cwd, PATH_MAX);
  my_setenv(&app->env, "PWD", new_cwd);
  free(new_cwd);
  return (0);
}

t_err	builtin_cd(t_application *app, int argc, char **argv)
{
  char	*new_cwd;

  if (argc < 2)
    new_cwd = my_getenv(app->env, "HOME");
  else
    new_cwd = argv[1];
  if (new_cwd == NULL)
    new_cwd = "/";
  if (my_strcmp(new_cwd, "-") == 0)
    {
      if (app->cd_history == NULL)
	return (print_error(ERROR_END_OF_HISTORY, "cd"));
      new_cwd = app->cd_history;
    }
  return (builtin_cd_change_dir(app, new_cwd));
}
