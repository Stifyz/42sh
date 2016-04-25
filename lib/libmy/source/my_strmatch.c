/*
** my_strmatch.c for  in /blinux_home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Jan 23 11:22:07 2016 Quentin Bazin
** Last update Sat Jan 23 11:22:07 2016 Quentin Bazin
*/

#include "my.h"

int	my_strmatch(char *s1, char *s2)
{
  if (*s2 == '*')
    {
      if (*s1 != '\0')
	return (my_strmatch(s1 + 1, s2) || my_strmatch(s1, s2 + 1));
      return (my_strmatch(s1, s2 + 1));
    }
  if (*s1 == *s2)
    {
      if (*s1 != '\0')
	return (my_strmatch(s1 + 1, s2 + 1));
      return (1);
    }
  return (0);
}
