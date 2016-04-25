/*
** my_strchr.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Mar 15 13:09:35 2016 Quentin Bazin
** Last update Tue Mar 15 13:09:35 2016 Quentin Bazin
*/

#include <my.h>

char		*my_strchr(char *str, char c)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (str + i);
      ++i;
    }
  return (NULL);
}

size_t		my_strichr(const char *str, char c)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      ++i;
    }
  return (-1);
}
