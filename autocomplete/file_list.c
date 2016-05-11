/*
** file_list.c for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:54:46 2016 Nicolas Zimmermann
** Last update Wed May 11 16:50:44 2016 Nicolas Zimmermann
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

void		list_file(t_autocomp *autoc)
{
  t_file	*tmp[2];
  DIR		*dir[NB_PATHES];
  int		i;

  autoc->head = malloc(sizeof(t_file));
  tmp[0] = autoc->head;
  tmp[1] = NULL;
  init_dir(dir);
  autoc->nb_elem = 0;
  i = -1;
  while (dir[++i])
    {
      while ((tmp[0]->file_name = give_filename(dir[i], autoc->buf)))
	{
	  autoc->nb_elem++;
	  tmp[0]->next = malloc(sizeof(t_file));
	  tmp[1] = tmp[0];
	  tmp[0] = tmp[0]->next;
	}
      closedir(dir[i]);
    }
  free(tmp[0]);
  if (tmp[1])
    tmp[1]->next = NULL;
  else
    autoc->head = NULL;
}
