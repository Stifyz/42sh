/*
** my_strmcat.c for  in /blinux_home/bazin_q/rendu/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Dec 04 16:03:18 2015 Quentin Bazin
** Last update Fri Dec 11 16:29:43 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

/*
** WARNING: 'dest' must be a null pointer or an allocated string
*/
char	*my_strcatm(char *dest, const char *src)
{
  char	*new_string;

  if (src == NULL)
    return (NULL);
  if ((new_string = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  new_string[0] = '\0';
  if (dest != NULL)
    {
      my_strcpy(new_string, dest);
      free(dest);
    }
  my_strcat(new_string, src);
  return (new_string);
}

char	*my_strncatm(char *dest, const char *src, int n)
{
  char	*new;
  int	dest_len;
  int	i;

  i = 0;
  if (n <= 0)
    return (dest);
  dest_len = my_strlen(dest);
  if ((new = malloc(dest_len + n + 1)) == NULL)
    return (NULL);
  while (i < dest_len + n)
    {
      if (i < dest_len)
	new[i] = dest[i];
      else
	new[i] = src[i - dest_len];
      ++i;
    }
  new[dest_len + n] = '\0';
  free(dest);
  return (new);
}
