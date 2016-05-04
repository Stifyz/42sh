/*
** env.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 17:24:50 2016 Quentin Bazin
** Last update Fri Mar 25 17:24:50 2016 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include <unistd.h>
#include "env.h"

t_env	*env_init(char **base_env)
{
  t_env	*env;
  t_env	*tmp;
  t_env	*first;

  env = NULL;
  first = NULL;
  while (base_env != NULL && *base_env != NULL)
    {
      if ((tmp = env_init_variable(*base_env)) == NULL)
	return (NULL);
      if (env == NULL)
	first = tmp;
      else
	env->next = tmp;
      env = tmp;
      ++base_env;
    }
  return (first);
}

t_env	*env_init_variable(char *base_env)
{
  t_env	*env;

  if ((env = malloc(sizeof(t_env))) == NULL)
    return (NULL);
  env->name = NULL;
  env->value = NULL;
  env->next = NULL;
  if ((env->name = my_strndup(base_env, VAL_OFFSET_ - base_env - 1)) == NULL
      || (env->value = my_strdup(VAL_OFFSET_)) == NULL)
    return (NULL);
  return (env);
}

char	**env_to_strarray(t_env *env)
{
  char	**array;
  t_env	*tmp;
  int	i;

  i = 0;
  tmp = env;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      ++i;
    }
  if (i == 0 || (array = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (env != NULL)
    {
      array[i] = NULL;
      array[i] = my_strcatm(array[i], env->name);
      array[i] = my_strcatm(array[i], "=");
      array[i] = my_strcatm(array[i], env->value);
      ++i;
      env = env->next;
    }
  array[i] = NULL;
  return (array);
}

char	*env_get_prog_path(char **env_path, char *prog_name)
{
  char	*path;
  int	i;

  i = 0;
  if (!prog_name)
    return (NULL);
  if (*prog_name == '/' || my_strstr(prog_name, "./") == prog_name)
    return (my_strdup(prog_name));
  while (env_path && env_path[i])
    {
      if (!(path = my_strdup(env_path[i]))
	  || (path[my_strlen(path) - 1] != '/'
	      && !(path = my_strcatm(path, "/")))
	  || !(path = my_strcatm(path, prog_name)))
	return (NULL);
      if (access(path, R_OK | X_OK) == 0)
	return (path);
      free(path);
      ++i;
    }
  return (NULL);
}

void	env_free(t_env *env)
{
  t_env	*tmp;

  while (env != NULL)
    {
      tmp = env;
      env = env->next;
      if (tmp->name != NULL)
	free(tmp->name);
      if (tmp->value != NULL)
	free(tmp->value);
      free(tmp);
    }
}
