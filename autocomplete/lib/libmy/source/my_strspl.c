/*
** my_strspl.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Apr 10 11:03:11 2016 Quentin Bazin
** Last update Sun Apr 10 11:03:11 2016 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char		**my_strspl(const char *str, char delim)
{
  char		**array;
  const char	*tmp;
  int		i;

  if (!str || !(array = malloc((my_strcnt(str, delim) + 2) * sizeof(char *))))
    return (NULL);
  i = 0;
  tmp = str;
  while (*tmp)
    {
      if (*tmp == delim)
	{
	  array[i++] = my_strndup(str, tmp - str);
	  str = tmp + 1;
	}
      ++tmp;
    }
  array[i++] = my_strdup(str);
  array[i] = NULL;
  return (array);
}
