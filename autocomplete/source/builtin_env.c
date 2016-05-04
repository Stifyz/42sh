/*
** builtin_env.c for  in /blinux_home/bazin_q/rendu/PSU/PSU_2015_minishell1/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Jan 21 11:29:55 2016 Quentin Bazin
** Last update Thu Jan 21 11:29:55 2016 Quentin Bazin
*/

#include <my.h>
#include <my_printf.h>
#include "application.h"

t_err	my_str_isvarname(char *str)
{
  if (str == NULL || my_is_num(*str))
    return (0);
  while (*str != '\0')
    {
      if (!my_is_alphanum(*str) && *str != '_')
	return (0);
      ++str;
    }
  return (1);
}

t_err	builtin_setenv(t_application *app, int argc, char **argv)
{
  char	*value;

  value = NULL;
  if (argc < 2)
    return (builtin_env(app, argc, argv));
  if (argc > 3)
    return (print_error(ERROR_TOO_MANY_ARGUMENTS, "setenv"));
  if (argc == 3)
    value = argv[2];
  if (!my_str_isvarname(argv[1]))
    return (print_error(ERROR_VARIABLE_NAME_INVALID, "setenv"));
  my_setenv(&app->env, argv[1], value);
  if (my_strcmp(argv[1], "PATH") == 0)
    {
      my_free_str_array(app->path);
      app->path = my_str_to_array(my_getenv(app->env, "PATH"), ":");
    }
  return (0);
}

t_err	builtin_unsetenv(t_application *app, int argc, char **argv)
{
  int	i;

  if (argc < 2)
    return (print_error(ERROR_TOO_FEW_ARGUMENTS, "unsetenv"));
  i = 1;
  while (i < argc)
    {
      my_unsetenv(&app->env, argv[i]);
      ++i;
    }
  my_free_str_array(app->path);
  app->path = my_str_to_array(my_getenv(app->env, "PATH"), ":");
  return (0);
}

t_err	builtin_env(t_application *app, int argc, char **argv)
{
  t_env	*env;

  (void)argc;
  (void)argv;
  env = app->env;
  while (env != NULL)
    {
      my_printf("%s=%s\n", env->name, env->value);
      env = env->next;
    }
  return (0);
}
