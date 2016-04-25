/*
** my_strcpy.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 09:51:26 2015 Quentin Bazin
** Last update Sat Nov 14 02:16:45 2015 Quentin Bazin
*/

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
