/*
** my_revstr.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 11:27:23 2015 Quentin Bazin
** Last update Wed Oct  7 18:55:20 2015 Quentin Bazin
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_revstr(char *str)
{
  char	c;
  int	i;

  i = 0;
  if (str == NULL)
    {
      return (str);
    }
  while (i < my_strlen(str) / 2)
    {
      c = str[i];
      str[i] = str[my_strlen(str) - i - 1];
      str[my_strlen(str) - i - 1] = c;
      i = i + 1;
    }
  return (str);
}
