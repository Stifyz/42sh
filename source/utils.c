/*
** utils.c for  in /blinux_home/bazin_q/rendu/PSU/PSU_2015_minishell1/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Jan 23 21:34:13 2016 Quentin Bazin
** Last update Sat Jan 23 21:34:13 2016 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include "utils.h"

void	my_epur_array(char **array)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (array[i])
    {
      if (!array[i][0])
	{
	  free(array[i]);
	  ++i;
	  continue;
	}
      array[j] = array[i];
      ++i;
      ++j;
    }
  array[j] = NULL;
}

int	my_is_valid(char c)
{
  return ((c > 31 && c != 127) || c == '\t');
}

int	my_cmd_isvalid(char *str)
{
  if (str == NULL)
    return (0);
  while (*str != '\0')
    {
      if (!my_is_valid(*str))
	return (0);
      ++str;
    }
  return (1);
}
