/*
** my_str_islower.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 18:01:10 2015 Quentin Bazin
** Last update Mon Oct  5 18:32:23 2015 Quentin Bazin
*/

#include "my.h"

bool	my_str_islower(char *str)
{
  if (!str)
    return (false);
  while (*str != '\0')
    {
      if (!(*str >= 'a' && *str <= 'z'))
	return (false);
      ++str;
    }
  return (true);
}
