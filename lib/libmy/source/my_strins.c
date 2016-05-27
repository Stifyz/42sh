/*
** my_strins.c for  in /home/bazin_q/rendu/Piscine_C_bistromathique/lib/my
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Oct 31 18:34:54 2015 Quentin Bazin
** Last update Sat Oct 31 18:35:07 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char	*my_strins(char *str, char c, unsigned int pos)
{
  int	i;

  i = my_strlen(str) + 1;
  while (i >= 0)
    {
      if ((unsigned int)i > pos)
	str[i] = str[i - 1];
      else if ((unsigned int)i == pos)
	str[i] = c;
      --i;
    }
  return (str);
}

char		*my_strinsm(char *str, char c, unsigned int pos)
{
  unsigned int	length;
  char		*new;

  length = my_strlen(str);
  if (!str || pos > length || !(new = malloc(length + 2)))
    return (NULL);
  my_strncpy(new, str, pos);
  new[pos] = c;
  my_strcpy(new + pos + 1, str + pos);
  free(str);
  return (new);
}
