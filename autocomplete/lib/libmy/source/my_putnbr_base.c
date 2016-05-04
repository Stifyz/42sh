/*
** my_putnbr_base.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 21:55:36 2015 Quentin Bazin
** Last update Fri Oct  9 09:17:04 2015 Quentin Bazin
*/

#include <my.h>

void			my_putnbr_base_rec(unsigned long int nb, char *base)
{
  unsigned long int	base_n;

  base_n = my_strlen(base);
  if (nb > base_n - 1)
    my_putnbr_base_rec(nb / base_n, base);
  my_putchar(base[nb % base_n]);
}

long int		my_putnbr_base(long int nb, char *base)
{
  unsigned long int	n;

  n = nb;
  if (!base || my_strlen(base) == 0)
    return (nb);
  if (nb < 0)
    {
      my_putchar('-');
      n = -nb;
    }
  my_putnbr_base_rec(n, base);
  return (nb);
}
