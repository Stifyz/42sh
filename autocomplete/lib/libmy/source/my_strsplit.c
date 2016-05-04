/*
** my_strsplit.c for  in /blinux_home/bazin_q/rendu/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Dec 04 18:39:04 2015 Quentin Bazin
** Last update Fri Dec 11 16:32:11 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

/*
** WARNING: This function returns an allocated substring of 'str'.
** Don't forget to free it.
*/
char	*my_strsplit(char *str, const char *delim, int part)
{
  char	*tmp;
  char	*ret;
  int	size;
  int	i;

  i = 0;
  ret = NULL;
  while (i <= part)
    {
      if ((tmp = my_strstr(str, delim)) == NULL)
	return ((i == part && *str != '\0') ? my_strdup(str) : NULL);
      size = tmp - str;
      if (size == 0)
	{
	  str += my_strlen(delim);
	  continue;
	}
      if (i == part && (ret = my_strndup(str, size)) == NULL)
	return (NULL);
      str = tmp + my_strlen(delim);
      ++i;
    }
  return (ret);
}
