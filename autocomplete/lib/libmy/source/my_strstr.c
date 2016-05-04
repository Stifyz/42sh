/*
** my_strstr.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 11:36:52 2015 Quentin Bazin
** Last update Fri Dec 11 16:38:20 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strstr(char *str, const char *to_find)
{
  int	i;
  int	to_find_pos;
  int	to_find_len;

  i = 0;
  to_find_pos = 0;
  to_find_len = my_strlen(to_find);
  if (str == NULL || to_find == NULL)
    return (NULL);
  if (to_find[0] == '\0')
    return (str);
  while (str[i] != '\0')
    {
      if (str[i] == to_find[to_find_pos])
	{
	  to_find_pos = to_find_pos + 1;
	  if (to_find_pos >= to_find_len)
	    return (&str[i + 1 - to_find_pos]);
	}
      else
	to_find_pos = 0;
      ++i;
    }
  return (NULL);
}
