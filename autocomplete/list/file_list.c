/*
** file_list.c for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:54:46 2016 Nicolas Zimmermann
** Last update Tue May 31 20:08:39 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <stdlib.h>
#include "autocomplete.h"

void	init_dir(DIR *dir[NB_PATHES])
{
  dir[0] = opendir(".");
  dir[1] = opendir("/bin");
  dir[2] = opendir("/sbin");
  dir[3] = opendir("/usr/bin");
  dir[4] = opendir("/usr/sbin");
  dir[5] = opendir("/usr/heimdal/bin");
  dir[6] = opendir("/usr/heimdal/sbin");
  dir[7] =  NULL;
}

/*
**   dir[7] = opendir("/home/$USR/bin");
**   !need env!
*/

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
  tmp->nb = autoc->nb_elem++;
  if (!(tmp->next = malloc(sizeof(t_file))))
    exit (0);
  tmp->next->prev = tmp;
  return (tmp->next);
}

void		list_file(t_autocomp *autoc)
{
  t_file	*tmp;
  DIR		*dir[NB_PATHES];
  int		i;

  if (!(autoc->head = malloc(sizeof(t_file))))
    exit (0);
  autoc->head->prev = NULL;
  tmp = autoc->head;
  init_dir(dir);
  autoc->nb_elem = 0;
  i = -1;
  while (dir[++i])
    {
      while ((tmp->file_name = give_filename(dir[i], autoc->buf)))
	tmp = add_file_elem(autoc, tmp);
      closedir(dir[i]);
    }
  if (tmp == autoc->head)
    {
      free(tmp);
      autoc->head = NULL;
      return ;
    }
  tmp->prev->next = NULL;
  free(tmp);
}
