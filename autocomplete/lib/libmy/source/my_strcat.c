/*
** my_strcat.c for Piscine_C_J07 in /home/bazin_q/rendu/Piscine_C_J07
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Oct  6 11:17:38 2015 Quentin Bazin
** Last update Fri Dec 11 16:34:17 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *dest, const char *src)
{
  int	dest_length;
  int	i;

  if (dest == NULL || src == NULL)
    return (NULL);
  dest_length = my_strlen(dest);
  i = 0;
  while (src[i] != '\0')
    {
      dest[dest_length + i] = src[i];
      ++i;
    }
  dest[dest_length + i] = '\0';
  return (dest);
}
