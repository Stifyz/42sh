/*
** my_strcmp.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 14:08:33 2015 Quentin Bazin
** Last update Mon Nov 30 00:38:48 2015 Quentin Bazin
*/

#include "my.h"

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (!s1 || !s2)
    return (!s1 && !s2 ? 0 : -1);
  while (i <= my_max(my_strlen(s1), my_strlen(s2)))
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  return (0);
}
