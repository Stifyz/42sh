/*
** echo_flag.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Jun 05 19:23:35 2016 Quentin Bazin
** Last update Sun Jun 05 19:23:35 2016 Quentin Bazin
*/

#include "echo.h"

void	flag_echo(char **av, int j, int *bf, int *b)
{
  if (av[1][j] == 'n')
    {
      if (!(*bf & 2))
	*bf += 2;
      else
	*b = 1;
    }
  else
    {
      *bf = 0;
      *b = 1;
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
	flag_echo(av, j, &bf, &b);
    }
  else
    b = 1;
  if (av[1][1] == 0)
    b = 1;
  treat_echo(ac, av, bf, b);
  return (0);
}
