/*
** unalias.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Jun 05 18:51:45 2016 Quentin Bazin
** Last update Sun Jun 05 18:51:45 2016 Quentin Bazin
*/

#include <my.h>
#include "application.h"

void		remove_alias(t_application *app, char **av,
			     t_alias *prev, t_alias *alias)
{
  int		i;

  i = 1;
  while (av[i])
    {
      if (my_strmatch(alias->name, av[i]))
	{
	  if (prev)
	    prev->next = alias->next;
	  else
	    app->alias_list = alias->next;
	  free(alias->name);
	  free(alias->cmd);
	  free(alias);
	}
      ++i;
    }
}

t_err		builtin_unalias(t_application *app, int ac, char **av)
{
  t_alias	*tmp;
  t_alias	*prev;
  t_alias	*next;

  if (ac == 1)
    return (print_error(ERROR_TOO_FEW_ARGUMENTS, av[0]));
  tmp = app->alias_list;
  prev = NULL;
  while (tmp)
    {
      next = tmp->next;
      remove_alias(app, av, prev, tmp);
      prev = tmp;
      tmp = next;
    }
  return (0);
}
