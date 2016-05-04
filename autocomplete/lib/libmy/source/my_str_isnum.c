/*
** my_str_isnum.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 18:01:10 2015 Quentin Bazin
** Last update Mon Oct  5 18:29:43 2015 Quentin Bazin
*/

#include <stdlib.h>

int	my_str_isnum(const char *str)
{
  if (str == NULL || str[0] == '\0')
    return (0);
  while (*str != '\0')
    {
      if (*str < '0' || *str > '9')
	return (0);
      ++str;
    }
  return (1);
}
