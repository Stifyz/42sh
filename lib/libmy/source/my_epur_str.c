/*
** my_epur_str.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Apr 15 12:43:55 2016 Quentin Bazin
** Last update Fri Apr 15 12:43:55 2016 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char	*my_epur_str(char *str)
{
  char	*new;
  char	*tmp;
  int	space;
  int	i;

  i = 0;
  tmp = str;
  if (!(new = malloc(my_strlen(str) + 1)))
    return (NULL);
  while (*tmp)
    {
      space = 0;
      while (*tmp && (*tmp == ' ' || *tmp == '\t'))
	{
	  space = 1;
	  ++tmp;
	}
      if (space)
	new[i++] = ' ';
      new[i++] = *tmp;
      ++tmp;
    }
  new[i] = '\0';
  free(str);
  return (new);
}
