/*
** my_put_nbr.c for Piscine_C_J03 in /home/bazin_q/rendu/Piscine_C_J03
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Sep 30 18:46:19 2015 Quentin Bazin
** Last update Tue Oct  6 10:55:50 2015 Quentin Bazin
*/

void	my_putchar(char c);

void	my_put_nbr_recursive(unsigned int nb)
{
  if (nb > 9)
    {
      my_put_nbr_recursive(nb / 10);
    }
  my_putchar('0' + nb % 10);
}

int		my_put_nbr(int nb)
{
  unsigned int	n;

  n = nb;
  if (nb < 0)
    {
      my_putchar('-');
      n = -nb;
    }
  my_put_nbr_recursive(n);
  return (0);
}
