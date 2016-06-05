/*
** echo2.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 23:13:47 2016 Bouama_r
** Last update Sun Jun  5 17:39:49 2016 Nicolas Zimmermann
*/

#include "echo.h"
#include <my.h>

inline bool my_is_octal(char c)
{
  return (c >= '0' && c <= '7');
}

int	treat_echo(int ac, char **av, int bf)
{
  if ((bf & 1) && ac == 2)
    return (0);
  if (bf & 1)
    flag_e(av, (bf != 0));
  else
    disp_normal(av, (bf != 0));
  if (!(bf & 2))
    my_putchar('\n');
  return (0);
}

int	check_space(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] != '-' || str[i] != 'n' || str[i] != 'e')
	return (-1);
      i++;
    }
  return (0);
}
