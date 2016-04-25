/*
** my_strcnt.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Apr 04 17:02:36 2016 Quentin Bazin
** Last update Mon Apr 04 17:02:36 2016 Quentin Bazin
*/

#include <my.h>

int	my_strcnt(const char *str, char c)
{
  int	i;

  i = 0;
  while (*str)
    {
      if (*str == c)
	++i;
      ++str;
    }
  return (i);
}
