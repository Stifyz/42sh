/*
** my_power_rec.c for Piscine_C_J05 in /home/bazin_q/rendu/Piscine_C_J05
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Oct  3 09:42:35 2015 Quentin Bazin
** Last update Tue Oct 27 17:36:54 2015 Quentin Bazin
*/

int	my_power_rec(int nb, int power)
{
  if (power == 0)
    {
      return (1);
    }
  else if (power < 0)
    {
      return (1 / my_power_rec(nb, -power));
    }
  else
    {
      return (nb * my_power_rec(nb, power - 1));
    }
}
