/*
** my_find_prime_sup.c for Piscine_C_J05 in /home/bazin_q/rendu/Piscine_C_J05
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 09:46:35 2015 Quentin Bazin
** Last update Tue Oct  6 10:45:41 2015 Quentin Bazin
*/

int	my_is_prime(int nb);

int	my_find_prime_sup(int nb)
{
  if (nb < 2)
    return (2);
  while (!my_is_prime(nb))
    {
      nb = nb + 1;
    }
  return (nb);
}
