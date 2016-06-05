/*
** echo.c for 42sh in /home/bouamar/rendu/PSU_2015_42sh/source
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 18:49:32 2016 Bouama_r
** Last update Sun Jun  5 18:29:49 2016 Nicolas Zimmermann
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

void	disp_normal(char **av, int b)
{
  int	j;

  j = b + 1;
  while (av[j] != NULL)
    {
      if (j != b + 1)
	my_putchar(' ');
      my_putstr(av[j]);
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
  int	bf;
  int	j;
  int	b;

  bf = 0;
  b = 0;
  if (av[1][0] == '-')
    {
      j = 0;
      while (b == 0 && av[1][++j] != '\0')
  	if (av[1][j] == 'e')
  	  {
  	    if (!(bf & 1))
  	      bf += 1;
  	    else
  	      b = 1;
  	  }
  	else if (av[1][j] == 'n')
  	  {
  	    if (!(bf & 2))
  	      bf += 2;
  	    else
  	      b = 1;
  	  }
  	else
	  {
	    bf = 0;
	    b = 1;
	  }
    }
  else
    b = 1;
  if (av[1][1] == 0)
    b = 1;
  treat_echo(ac, av, bf, b);
  return (0);
}
