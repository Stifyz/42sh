/*
** my_strncat.c for Piscine_C_J07 in /home/bazin_q/rendu/Piscine_C_J07
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Oct  6 13:46:14 2015 Quentin Bazin
** Last update Fri Oct  9 09:25:52 2015 Quentin Bazin
*/

#include "my.h"

char	*my_strncat(char *dest, const char *src, int n)
{
  int	dest_length;
  int	i;

  i = 0;
  if (!dest || !src)
    return (0);
  if (n == 0)
    return (dest);
  if (n < 0)
    n = my_strlen(src);
  dest_length = my_strlen(dest);
  while (i < n && src[i] != '\0')
    {
      dest[dest_length + i] = src[i];
      ++i;
    }
  dest[dest_length + i] = '\0';
  return (dest);
}
