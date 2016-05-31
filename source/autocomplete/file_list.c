/*
** file_list.c for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:54:46 2016 Nicolas Zimmermann
** Last update Tue May 31 22:10:30 2016 Nicolas Zimmermann
*/

#include <dirent.h>
#include <my.h>
#include <stdlib.h>
#include "autocomplete.h"

DIR	**init_dir(char **pathes)
{
  DIR	**dir;
  int	i;

  i = -1;
  while (pathes[++i]);
  if (!(dir = malloc(sizeof(DIR *) * (i + 2))))
    exit(0);
  i = -1;
  while (pathes[++i])
    dir[i] = opendir(pathes[i]);
  dir[i++] = opendir(".");
  dir[i] = NULL;
  return (dir);
}

char		*give_filename(DIR *dir, char *buff)
{
  struct dirent *s_dir;

  while ((s_dir = readdir(dir)) != NULL)
    {
      if (my_strncmp(s_dir->d_name, buff, my_strlen(buff)) == 0)
	return (my_strdup(s_dir->d_name));
    }
  return (NULL);
}

t_file	*add_file_elem(t_autocomp *autoc, t_file *tmp)
{
  tmp->len = my_strlen(tmp->file_name);
  autoc->nb_elem++;
  if (!(tmp->next = malloc(sizeof(t_file))))
    exit (0);
  tmp->next->prev = tmp;
  return (tmp->next);
}

void		list_file(t_autocomp *autoc, char **pathes)
{
  t_file	*tmp;
  DIR		**dir;
  int		i;

  if (!(autoc->head = malloc(sizeof(t_file))))
    exit (0);
  autoc->head->prev = NULL;
  tmp = autoc->head;
  dir = init_dir(pathes);
  autoc->nb_elem = 0;
  i = -1;
  while (dir[++i])
    {
      while ((tmp->file_name = give_filename(dir[i], autoc->buf)))
	tmp = add_file_elem(autoc, tmp);
      closedir(dir[i]);
    }
  free(dir);
  if (tmp == autoc->head)
    {
      free(tmp);
      autoc->head = NULL;
      return ;
    }
  tmp->prev->next = NULL;
  free(tmp);
}
