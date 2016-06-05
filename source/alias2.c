/*
** alias2.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Sun Jun  5 03:05:28 2016 Bouama_r
** Last update Sun Jun  5 14:35:55 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "alias.h"
#include "application.h"
#include "error.h"

t_err		update_alias(t_alias *tmp, char *cmd, char *name)
{
  free(tmp->cmd);
  if (!(tmp->cmd = my_strdup(cmd)))
    return (print_error(ERROR_MALLOC_FAILED));
  free(cmd);
  free(name);
  return (0);
}

t_err		attribution(t_application *app, char *name, char *cmd)
{
  t_alias	*tmp;
  char		**av;

  if (!(av = malloc(sizeof(char *) * 2)))
    return (print_error(ERROR_MALLOC_FAILED));
  av[0] = name;
  av[1] = NULL;
  if (!(tmp = search_alias(app, av)))
    {
      if (!(tmp = alias_new(name, cmd)))
	return (print_error(ERROR_MALLOC_FAILED));
      tmp->next = app->alias_list;
      app->alias_list = tmp;
    }
  else
    {
      free(av);
      return (update_alias(tmp, cmd, name));
    }
  free(av);
  return (0);
}

void		print_alias_info(t_application *app, char **av)
{
  t_alias	*tmp;

  tmp = app->alias_list;
  while (tmp)
    {
      if (my_strcmp(av[1], tmp->name) == 0)
	{
	  my_putstr(tmp->cmd);
	  my_putchar('\n');
	  return ;
	}
      tmp = tmp->next;
    }
}
