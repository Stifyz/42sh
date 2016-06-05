/*
** autocomplete_folder.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/source/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Sat Jun  4 03:40:08 2016 Nicolas Zimmermann
** Last update Sun Jun  5 00:28:56 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <stdlib.h>
#include "autocomplete.h"

t_err	autocomplete_folder(char *arg, t_autocomp *autoc)
{
  int	i;
  int	len;
  char	**pathes;
  t_err	err;

  len = my_strlen(arg);
  i = len;
  while (arg[--i] != '/');
  if (!(pathes = malloc(sizeof(char *) * 2)) ||
      !(pathes[0] = my_strndup(arg, i)))
    return (print_error(ERROR_MALLOC_FAILED));
  if (arg[i + 1])
    {
      if (!(autoc->buf = my_strdup(&arg[i + 1])))
	return (print_error(ERROR_MALLOC_FAILED));
    }
  else
    autoc->buf = NULL;
  pathes[1] = NULL;
  if ((err = file_list(autoc, pathes)))
    return (err);
  free(pathes[0]);
  free(pathes);
  return (0);
}
