/*
** my_showmem.c for  in /home/bazin_q/rendu/Piscine_C_J07/lib/my/src
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Oct  6 11:03:10 2015 Quentin Bazin
** Last update Sun Nov 15 16:23:40 2015 Quentin Bazin
*/

#include <stdint.h>
#include <stdlib.h>
#include "my.h"

int	my_digit_count(int64_t n, int base)
{
  if (n < base)
    {
      return (1);
    }
  else
    {
      return (1 + my_digit_count(n / base, base));
    }
}

void		my_showmem_print_addr(char *str, int line_num)
{
  int		i;
  int64_t	n;

  n = (int64_t)(str + line_num * 16);
  i = 0;
  while (my_digit_count(n, 16) + i < 8)
    {
      my_putchar('0');
      i = i + 1;
    }
  my_putnbr_base(n, "0123456789abcdef");
}

void	my_showmem_print_hex_chars(char *str, int num_chars)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if (i < num_chars)
	{
	  if (str[i] < 0)
	    my_putstr("00");
	  else
	    {
	      if (str[i] < 16)
		my_putchar('0');
	      my_putnbr_base(str[i], "0123456789abcdef");
	    }
	}
      else
	my_putstr("  ");
      if ((i + 1) % 2 == 0)
	my_putchar(' ');
      i = i + 1;
    }
}

void	my_showmem_print_chars(char *str, int num_chars)
{
  int	i;

  i = 0;
  while (i < 16 && i < num_chars)
    {
      if (my_is_printable(str[i]))
	my_putchar(str[i]);
      else
	my_putchar('.');
      ++i;
    }
}

int		my_showmem(char *str, int size)
{
  int		i;

  i = 0;
  if (str == NULL || size < 1)
    return (0);
  while (i < (size + 0.5f) / 16)
    {
      my_showmem_print_addr(str + i * 16, i);
      my_putstr(": ");
      my_showmem_print_hex_chars(str + i * 16, size - i * 16);
      my_putchar(' ');
      my_showmem_print_chars(str + i * 16, size - i * 16);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
