/*
** my_strncmp.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 16:40:58 2015 Quentin Bazin
** Last update Mon Nov 30 00:43:36 2015 Quentin Bazin
*/

#include "my.h"

int	my_strncmp(const char *s1, const char *s2, int n)
{
  int	i;

  i = 0;
  while (i <= my_max(my_strlen(s1), my_strlen(s2)) && i < n)
    {
      if (s1[i] != s2[i])
	{
	  return (s1[i] - s2[i]);
	}
      i = i + 1;
    }
  return (0);
}
