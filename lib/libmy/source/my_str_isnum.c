/*
** my_str_isnum.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 18:01:10 2015 Quentin Bazin
** Last update Mon Oct  5 18:29:43 2015 Quentin Bazin
*/

#include "my.h"

bool	my_str_isnum(const char *str)
{
  if (!str || !str[0])
    return (false);
  while (*str)
    {
      if (*str < '0' || *str > '9')
	return (false);
      ++str;
    }
  return (true);
}
