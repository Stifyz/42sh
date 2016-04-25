/*
** my_strdup.c for Piscine_C_J08 in /home/bazin_q/rendu/Piscine_C_J08
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Oct  7 09:29:53 2015 Quentin Bazin
** Last update Mon Jan 04 08:47:46 2016 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(const char *src)
{
  char	*cpy;
  int	i;

  i = 0;
  if (src == NULL || (cpy = malloc(my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (i < my_strlen(src))
    {
      cpy[i] = src[i];
      ++i;
    }
  cpy[i] = '\0';
  return (cpy);
}

char	*my_strndup(const char *src, int n)
{
  char	*cpy;
  int	i;

  i = 0;
  if (src == NULL || n < 0 || (cpy = malloc(n + 1)) == NULL)
    return (NULL);
  while (i < n)
    {
      cpy[i] = src[i];
      ++i;
    }
  cpy[i] = '\0';
  return (cpy);
}
