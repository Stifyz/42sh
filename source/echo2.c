/*
** echo2.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 23:13:47 2016 Bouama_r
** Last update Fri Jun  3 00:32:48 2016 Bouama_r
*/

#include "echo.h"

inline bool my_is_octal(char c)
{
  return (c >= '0' && c <= '7');
}

int	check_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '-' || str[i] != 'n' || str[i] != 'e')
	return (-1);
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  my_echo(ac, av);
  return (0);
}
