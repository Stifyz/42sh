/*
** my_strncpy.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 10:34:22 2015 Quentin Bazin
** Last update Tue Oct  6 10:56:34 2015 Quentin Bazin
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (!dest || !src)
    return (NULL);
  if (n < 1)
    return (dest);
  while (i < n && src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  if (n > my_strlen(src))
    dest[i] = '\0';
  return (dest);
}
