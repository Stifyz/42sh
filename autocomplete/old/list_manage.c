/*
** list_manage.c for list_manage in /home/audet_b/Projets/PSU_2015_minishell2/src/list/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Wed Apr  6 02:55:46 2016 Benjamin Audet
** Last update Mon May  9 15:53:17 2016 Benjamin Audet
*/

#include "list.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

void		free_list(t_autocomp *head)
{
  t_autocomp	*tmp[2];

  tmp[0] = head;
  while ((tmp[0]))
    {
      free(tmp[0]->file_name);
      tmp[1] = tmp[0];
      tmp[0] = tmp[0]->next;
      free(tmp[1]);
    }
}

void		manage_list(t_autocomp *head)
{
  fill_list(head, "/bin", 1);
}

t_autocomp	*new_elem(char *var)
{
  t_autocomp	*tmp;

  tmp = malloc(sizeof(t_autocomp));
  tmp->file_name = malloc(my_strlen(var) + 1);
  tmp->file_name = my_strcpy(tmp->file_name, var);
  return (tmp);
}

void		fill_list(t_autocomp *head, char *path, int a)
{
  struct dirent	*s_dir;
  DIR		*dir;
  t_autocomp	*tmp;

  if ((dir = opendir(path)) == NULL)
    error_opendir();
  if ((s_dir = readdir(dir)) == NULL)
    error_readdir();
  if (a == 0)
    {
      tmp = head;
      while (tmp->next)
	tmp = tmp->next;
    }
  else
    {
      head = new_elem(s_dir->d_name);
      tmp = head;
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

void 		display_list(t_autocomp *head)
{
  t_autocomp 	*tmp;

  tmp = head;
  while (tmp != NULL)
    {
      my_putstr(tmp->file_name);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

void		display_element(t_autocomp *head, char *var)
{
  t_autocomp	*tmp;

  tmp = head;
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
