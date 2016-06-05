/*
** file_list.c for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:54:46 2016 Nicolas Zimmermann
** Last update Sun Jun  5 01:34:16 2016 Nicolas Zimmermann
*/

#include <dirent.h>
#include <my.h>
#include <stdlib.h>
#include "autocomplete.h"

DIR	**init_dir(char **pathes, bool is_folder)
{
  DIR	**dir;
  int	i;
  int	j;

  i = -1;
  while (pathes[++i]);
  if (!(dir = malloc(sizeof(DIR *) * (i + ((is_folder) ? 1 : 2)))))
    return (NULL);
  i = 0;
  j = -1;
  while (pathes[++j])
    if ((dir[i] = opendir(pathes[j])))
      i++;
  if (is_folder == false)
    dir[i++] = opendir(".");
  dir[i] = NULL;
  return (dir);
}

char		*give_filename(DIR *dir, char *buff, t_err *err)
{
  struct dirent *s_dir;
  char		*file_name;

  *err = 0;
  while ((s_dir = readdir(dir)) != NULL)
    {
      if (!buff || !my_strncmp(s_dir->d_name, buff, my_strlen(buff)))
	{
	  if (!(file_name = my_strdup(s_dir->d_name)))
	    {
	      *err = ERROR_MALLOC_FAILED;
	      return (NULL);
	    }
	  else if (!buff && file_name[0] == '.')
	    return (NULL);
	  else
	    return (file_name);
	}
    }
  return (NULL);
}

t_file	*add_file_elem(t_autocomp *autoc, t_file *tmp)
{
  tmp->len = my_strlen(tmp->file_name);
  autoc->nb_elem++;
  if (!(tmp->next = malloc(sizeof(t_file))))
    return (NULL);
  tmp->next->prev = tmp;
  return (tmp->next);
}

t_err		search_files(t_autocomp *autoc, DIR **dir)
{
  t_file	*tmp;
  int		i;
  t_err		err;

  tmp = autoc->head;
  i = -1;
  while (dir[++i] != NULL)
    {
      while ((tmp->file_name = give_filename(dir[i], autoc->buf, &err)))
	if (!(tmp = add_file_elem(autoc, tmp)))
	  return (print_error(ERROR_MALLOC_FAILED));
      if (err)
	return (print_error(ERROR_MALLOC_FAILED));
      closedir(dir[i]);
    }
  free(dir);
  if (tmp == autoc->head)
    autoc->head = NULL;
  else
    {
      tmp->prev->next = NULL;
      sort_list(autoc);
    }
  free(tmp);
  return (0);
}

t_err		file_list(t_autocomp *autoc, char **pathes)
{
  DIR	**dir;

  if (!(autoc->head = malloc(sizeof(t_file))))
    return (print_error(ERROR_MALLOC_FAILED));
  if (!(dir = init_dir(pathes, autoc->is_folder)))
    return (print_error(ERROR_MALLOC_FAILED));
  autoc->head->prev = NULL;
  autoc->nb_elem = 0;
  return (search_files(autoc, dir));
}
