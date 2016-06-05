/*
** alias2.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Sun Jun  5 03:05:28 2016 Bouama_r
** Last update Sun Jun  5 03:25:18 2016 Bouama_r
*/

#include <my.h>
#include "alias.h"
#include "application.h"
#include "error.h"

void		attribution(t_application *app, char *name, char *cmd)
{
  t_alias	*new;

  new = alias_new(name, cmd);
  new->next = app->alias_list;
  app->alias_list = new;
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
