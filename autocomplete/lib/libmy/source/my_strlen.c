/*
** my_strlen.c for Piscine_C_J04 in /home/bazin_q/rendu/Piscine_C_J04
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Oct  1 09:59:58 2015 Quentin Bazin
** Last update Fri Dec 11 16:32:07 2015 Quentin Bazin
*/

#include <stdlib.h>

int		my_strdlen(const char *str, char delim)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != delim && str[i] != '\0')
    ++i;
  return (i);
}

int		my_strlen(const char *str)
{
  return (my_strdlen(str, '\0'));
}
