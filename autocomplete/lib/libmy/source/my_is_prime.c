/*
** my_is_prime.c for Piscine_C_J05 in /home/bazin_q/rendu/Piscine_C_J05
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 09:11:04 2015 Quentin Bazin
** Last update Mon Oct  5 09:35:07 2015 Quentin Bazin
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  if (nb < 2)
      return (0);
  while (i < 46340 && i < nb / 2)
    {
      if (nb % i == 0)
	{
	  if (nb == i)
	      return (1);
	  else
	      return (0);
	}
      i = i + 1;
    }
  if (i == 46340)
      return (0);
  else
      return (1);
}
