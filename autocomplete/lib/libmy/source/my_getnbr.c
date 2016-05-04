/*
** my_getnbr.c for Piscine_C_J04 in /home/bazin_q/rendu/Piscine_C_J04
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Oct  1 11:58:54 2015 Quentin Bazin
** Last update Sun Nov 22 08:40:07 2015 Quentin Bazin
*/

#include <stdlib.h>

int		my_atoi(const char *str, int num_pos, int num_len, int sign)
{
  int		i;
  int		n;
  unsigned int	tmp;

  n = 0;
  i = num_pos;
  while (i < num_pos + num_len)
    {
      tmp = n * 10 + (str[i] - '0');
      if ((tmp <= 2147483648 && sign == -1)
	  || (tmp <= 2147483647 && sign == 1))
	n = tmp;
      else
	return (0);
      ++i;
    }
  return (sign * n);
}

int	my_getnbr(const char *str)
{
  int	i;
  int	num_pos;
  int	num_len;
  int	sign;

  sign = 1;
  i = 0;
  if (str == NULL)
    return (0);
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    {
      if (str[i] != '+' && str[i] != '-')
	return (0);
      ++i;
    }
  num_pos = i;
  if (i > 0 && str[i - 1] == '-')
    sign = -1;
  while (str[i] >= '0' && str[i] <= '9')
    ++i;
  num_len = i - num_pos;
  if (num_len > 10)
      return (0);
  return (my_atoi(str, num_pos, num_len, sign));
}
