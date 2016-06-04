/*
** alias.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Sat Jun  4 01:50:05 2016 Bouama_r
** Last update Sat Jun  4 04:32:08 2016 Bouama_r
*/

#include <my.h>
#include "alias.h"
#include "application.h"
#include "error.h"

t_alias		*search_alias(t_application *app, char **av)
{
  t_alias	*tmp;

  // my_putstr("search_alias\n");
  tmp = app->alias_list;
  // my_printf("%p\n", tmp);
  while (tmp)
    {
      // my_putstr(tmp->name);
      if (my_strcmp(av[0], tmp->name) != 0)
	return (tmp);
      tmp = tmp->next;
    }
  tmp = NULL;
  return (tmp);
}

t_err		alias_run(t_application *app, char **av)
{
  t_alias	*tmp;
  char		*cmd;
  int		i;

  i = 1;
  // my_putstr("alias_run: %p\n", app->alias_list);
  tmp = search_alias(app, av);
  if (tmp != NULL)
    {
      cmd = NULL;
      cmd = my_strcatm(cmd, tmp->cmd);
      while (av[i] != NULL)
	{
	  cmd = my_strcatm(cmd, " ");
	  cmd = my_strcatm(cmd, av[i]);
	  i++;
	}
      my_putstr(cmd);
      my_putchar('\n');
      application_run_command(app, cmd);
      return (true);
    }
  else
    return (false);
}

int		check_print_alias(t_application *app, int ac, char **av)
{
  t_alias	*tmp;

  tmp = app->alias_list;
  // my_printf("check_print_alias: %p\n", app->alias_list);
  if (ac == 1 && (my_strcmp(av[0], "alias") == 0))
    {
      // my_putstr("OK\n");
      // my_printf("%p\n", tmp);
      while (tmp)
	{
	  //my_putstr("tmp\n");
	  my_putstr(tmp->name);
	  my_putstr(" : ");
	  my_putstr(tmp->cmd);
	  my_putchar('\n');
	  tmp = tmp->next;
	}
      return (0);
    }
  return (-1);
}

t_alias		*alias_new(char *name, char *cmd)
{
  t_alias	*elem;

  // my_putstr("alias_new\n");
  elem = NULL;
  if ((elem = malloc(sizeof(t_alias))) == NULL)
    return (elem);
  my_memset(elem, 0, sizeof(t_alias));
  elem->name = my_strcatm(elem->name, name);
  elem->cmd = my_strcatm(elem->cmd, cmd);
  return (elem);
}

t_err		builtin_alias(t_application *app, int ac, char **av)
{
  char		*name;
  char		*cmd;
  t_alias	*new;
  int		i;

  i = 2;
  // my_putstr("builtin alias\n");
  if (ac == 1 && check_print_alias(app, ac, av) == 0)
    return (0);
  name = NULL;
  name = my_strcatm(name, av[1]);
  cmd = NULL;
  while (i < ac)
    {
      if (i != 2)
	cmd = my_strcatm(cmd, " ");
      cmd = my_strcatm(cmd, av[i]);
      i++;
    }
  new = alias_new(name, cmd);
  new->next = app->alias_list;
  app->alias_list = new;
  my_printf("%p\n", app->alias_list);
}
