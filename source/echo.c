/*
** echo.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 18:49:32 2016 Bouama_r
** Last update Sun Jun  5 18:46:06 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "echo.h"

t_err	builtin_echo(t_application *app, int ac, char **av)
{
  (void)app;
  if (ac == 1)
    {
      my_putchar('\n');
      return (0);
    }
  my_flag_echo(ac, av);
  return (0);
}

char    get_escaped_char(char *str, int pos)
{
  char  *chars;
  int   i;

  i = 0;
  chars = "abtnvfr";
  if (str[pos] == '\\')
    return ('\\');
  if (str[pos] == '0')
    {
      if (my_is_octal(pos + 1))
	return (my_getnbr_base(str + pos + 1, "01234567"));
      return (0);
    }
  while (chars[i])
    {
      if (chars[i] == str[pos])
	return (i + 7);
      ++i;
    }
  return (-1);
}

void	flag_e(char **av, int b)
{
  int		i;
  int		j;

  j = b + 1;
  while (av[j] != NULL)
    {
      i = -1;
      while (av[j][++i] != '\0')
	{
	  if (av[j][i] == '\\' && av[j][i + 1])
	    my_putchar(get_escaped_char(av[j], ++i));
	  else
	    my_putchar(av[j][i]);
	}
      j++;
      if (av[j])
	my_putchar(' ');
    }
}
