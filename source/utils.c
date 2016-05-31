/*
** utils.c for  in /blinux_home/bazin_q/rendu/PSU/PSU_2015_minishell1/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Jan 23 21:34:13 2016 Quentin Bazin
** Last update Sat Jan 23 21:34:13 2016 Quentin Bazin
*/

#include <asm-generic/ioctls.h>
#include <my.h>
#include <stdlib.h>
#include <stropts.h>
#include <termios.h>
#include <unistd.h>
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
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (!my_is_valid(str[i]))
	return (i);
      ++i;
    }
  return (-1);
}

int			my_getch_term() {
  struct termios	old_t;
  struct termios	new_t;
  char			buf[101];
  int			read_size;
  int			ch;
  int			i;

  ioctl(0, TCGETS, &old_t);
  new_t = old_t;
  new_t.c_lflag &= ~(ECHO | ICANON);
  ioctl(0, TCSETS, &new_t);
  if ((read_size = read(0, buf, 100)) == 0)
    return (-1);
  buf[read_size] = '\0';
  ioctl(0, TCSETS, &old_t);
  ch = 0;
  i = 0;
  while (buf[i])
    {
      ch <<= 7;
      ch |= buf[i];
      ++i;
    }
  return (ch);
}

int	my_getch()
{
  char	c;

  if (isatty(0))
    return (my_getch_term());
  if (read(0, &c, 1) == 0)
    return (-1);
  return (c);
}
