/*
** my_is_space.c for  in /home/bazin_q/rendu/Piscine_C_workshoplib/lib/my
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Oct 20 14:43:47 2015 Quentin Bazin
** Last update Tue Oct 20 14:44:44 2015 Quentin Bazin
*/

#include "my.h"

bool	my_is_space(char c)
{
  char	*spaces;

  spaces = " \f\n\r\t\v";
  while (*spaces)
  {
    if (*spaces == c)
      return (true);
    ++spaces;
  }
  return (false);
}
