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
#include "env.h"

char	*my_getenv(t_env *env, char *name)
{
  while (env != NULL)
    {
      if (my_strcmp(env->name, name) == 0)
	return (env->value);
      env = env->next;
    }
  return (NULL);
}

int	add_to_env(t_env **env, char *name, char *value)
{
  t_env	*tmp;

  if ((tmp = malloc(sizeof(t_env))) == NULL)
    return (-1);
  tmp->name = my_strdup(name);
  tmp->value = my_strdup(value);
  tmp->next = NULL;
  if (*env != NULL)
    (*env)->next = tmp;
  else
    *env = tmp;
  return (0);
}

int	my_setenv(t_env **envp, char *name, char *value)
{
  t_env	*env;

  if (*envp == NULL)
    return (add_to_env(envp, name, value));
  env = *envp;
  while (env != NULL)
    {
      if (my_strcmp(env->name, name) == 0)
	{
	  if (env->value != NULL)
	    free(env->value);
	  env->value = my_strdup(value);
	  return (0);
	}
      if (env->next == NULL)
	return (add_to_env(&env, name, value));
      env = env->next;
    }
  return (-1);
}

void	my_unsetenv(t_env **envp, char *pattern)
{
  t_env	*env;
  t_env	*prev;

  env = *envp;
  prev = NULL;
  while (env != NULL)
    {
      if (my_strmatch(env->name, pattern))
	{
	  if (prev == NULL)
	    *envp = env->next;
	  else
	    prev->next = env->next;
	  if (env->name != NULL)
	    free(env->name);
	  if (env->value != NULL)
	    free(env->value);
	  free(env);
	  env = (prev == NULL) ? *envp : prev->next;
	}
      else if ((prev = env) != NULL)
	env = env->next;
    }
}
