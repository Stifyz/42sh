/*
** my_printf_print_wrappers.c for  in /blinux_home/bazin_q/rendu/
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 29 19:08:04 2015 Quentin Bazin
** Last update Sun Nov 29 19:31:15 2015 Quentin Bazin
*/

#include <my.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

int	my_printf_putchar(char c, int fd)
{
  write(fd, &c, 1);
  return (1);
}

int	my_printf_putstr(char *str, int fd)
{
  int	i;

  i = 0;
  if (!str)
    return (0);
  while (str[i] != '\0')
    {
      my_printf_putchar(str[i], fd);
      ++i;
    }
  return (i);
}

uint64_t	my_printf_putulnbr_base(uint64_t nb, char *base, int fd)
{
  unsigned int	base_n;
  unsigned int	cpt_chars;

  if (!base || my_strlen(base) == 0)
    return (0);
  cpt_chars = 0;
  base_n = my_strlen(base);
  if (nb > base_n - 1)
    cpt_chars += my_printf_putulnbr_base(nb / base_n, base, fd);
  my_printf_putchar(base[nb % base_n], fd);
  return (cpt_chars + 1);
}

int64_t		my_printf_putlnbr_base(int64_t nb, char *base, int fd)
{
  unsigned int	chars;

  chars = 0;
  if (nb < 0)
    chars += my_printf_putchar('-', fd);
  chars += my_printf_putulnbr_base(my_abs(nb), base, fd);
  return (chars);
}

int	my_printf_showstr_oct(char *str, int fd)
{
  int	cpt;

  if (str == NULL)
    return (0);
  cpt = 0;
  while (*str != '\0')
    {
      if (!my_is_printable(*str))
	{
	  cpt += my_printf_putchar('\\', fd);
	  if (*str < 0100)
	    cpt += my_printf_putchar('0', fd);
	  if (*str < 010)
	    cpt += my_printf_putchar('0', fd);
	  cpt += my_printf_putulnbr_base(*str, "01234567", fd);
	}
      else
	cpt += my_printf_putchar(*str, fd);
      ++str;
    }
  return (cpt);
}
