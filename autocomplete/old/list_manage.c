/*
** list_manage.c for list_manage in /home/audet_b/Projets/PSU_2015_minishell2/src/list/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Wed Apr  6 02:55:46 2016 Benjamin Audet
** Last update Tue May 10 14:48:52 2016 Benjamin Audet
*/

#include "list.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void		free_list(t_list *list)
{
  t_element	*tmp[2];

  tmp[0] = list->first;
  while ((tmp[0]))
    {
      free(tmp[0]->file_name);
      tmp[1] = tmp[0];
      tmp[0] = tmp[0]->next;
      free(tmp[1]);
    }
}

void		manage_list(t_list *list)
{
  fill_list(list, "/bin", 1);
  fill_list(list, ".", 0);
  fill_list(list, "/sbin", 0);
 }

t_element	*new_elem(char *var)
{
  t_element	*tmp;

  tmp = malloc(sizeof(t_element));
  tmp->file_name = malloc(my_strlen(var) + 1);
  tmp->file_name = my_strcpy(tmp->file_name, var);
  return (tmp);
}

void		fill_list(t_list *list, char *path, int a)
{
  struct dirent	*s_dir;
  DIR		*dir;
  t_element	*tmp;

  if ((dir = opendir(path)) == NULL)
    error_opendir();
  if ((s_dir = readdir(dir)) == NULL)
    error_readdir();
  if (a == 1)
    {
      list->first = new_elem(s_dir->d_name);
      tmp = list->first;
    }
  while ((s_dir = readdir(dir)) != NULL)
    {
      if (s_dir->d_name[0] != '.')
	{
	  tmp->next = new_elem(s_dir->d_name);
	  tmp = tmp->next;
	}
    }
  tmp->next = NULL;
  closedir(dir);
}

void 		display_list(t_list *list)
{
  t_element 	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      my_putstr(tmp->file_name);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

void		display_element(t_list *list, char *var)
{
  t_element	*tmp;

  tmp = list->first;
  while (tmp != NULL)
    {
      if (my_strncmp(tmp->file_name, var, my_strlen(var)) == 0)
	{
	  my_putstr(tmp->file_name);
	  my_putchar('\n');
	  break;
	}
      tmp = tmp->next;
    }
}
