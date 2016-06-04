/*
** echo.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 18:49:32 2016 Bouama_r
** Last update Sun Jun  5 01:41:54 2016 Bouama_r
*/

#include <my.h>
#include "echo.h"

t_err	builtin_echo(t_application *app, int ac, char **av)
{
  int	i;

  i = 1;
  (void)app;
  if (ac == 1)
    {
      my_putchar('\n');
      return (0);
    }
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
  return (0);
}

void	disp_normal(char **av)
{
  int	j;

  j = 1;
  while (av[j] != NULL)
    {
      if (av[j][0] != '-')
	break;
      j++;
    }
  while (av[j] != NULL)
    {
      my_putstr(av[j]);
      my_putchar(' ');
      j++;
    }
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
  int		i;
  int		j;

  j = 0;
  (void)ac;
  while (av[++j] != NULL)
    {
      if (av[j][0] != '-')
	break;
    }
  while (av[j] != NULL)
    {
      i = -1;
      while (av[j][++i] != '\0')
	{
	  if (av[j][i] == '\\' && av[j][i + 1])
	    {
	      my_putchar(get_escaped_char(av[j], ++i));
	    }
	  else
	    my_putchar(av[j][i]);
	}
      j++;
      my_putchar(' ');
    }
}

int	my_flag_echo(int ac, char **av)
{
  int	i;
  int	n;
  int	e;
  int	j;

  i = 1;
  n = 0;
  e = 0;
  j = 0;
  while (av[i] && av[i][0] == '-' && check_space(av[i]) != 0)
    {
      while (av[i][j] != '\0')
	{
	  if (av[i][j] == 'n')
	    n = 1;
	  if (av[i][j] == 'e')
	    e = 1;
	  j++;
	}
      i++;
    }
  treat_echo(ac, av, n, e);
  return (0);
}
