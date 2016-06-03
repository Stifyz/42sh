/*
** echo.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 18:49:32 2016 Bouama_r
** Last update Fri Jun  3 22:15:38 2016 Bouama_r
*/

#include "echo.h"

void	builitin_echo(int ac, char **av)
{
  int	i;

  i = 1;
  if (av[1][0] == '-')
    my_flag_echo(ac, av);
  else
    {
      while (i < ac)
	{
	  if (i != 1)
	    my_putchar(' ');
	  my_putstr(av[i]);
	  i++;
	}
      my_putchar('\n');
    }
}

void	disp_normal(int ac, char **av)
{
  my_putstr(av[2]);
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

void	flag_e(int ac, char **av)
{
  int	i;

  i = 0;
  while (av[ac - 1][i] != '\0')
    {
      if (av[ac - 1][i] == '\\' && av[ac - 1][i + 1])
	{
	  my_putchar(get_escaped_char(av[ac - 1], ++i));
	}
      else
	my_putchar(av[ac - 1][i]);
      i++;
    }
}

void	my_flag_echo(int ac, char **av)
{
  int	i;
  int	n;
  int	e;
  int	j;

  i = 1;
  n = 0;
  e = 0;
  j = 0;
  while (av[i][0] == '-' && check_space(av[i]) != 0)
    {
      while (av[1][j] != '\0')
	{
	  if (av[1][j] == 'n')
	    n = 1;
	  if (av[1][j] == 'e')
	    e = 1;
	  j++;
	}
      i++;
    }
  if (e == 1)
    flag_e(ac, av);
  else
    disp_normal(ac ,av);
  if (n != 1)
    my_putchar('\n');
}
