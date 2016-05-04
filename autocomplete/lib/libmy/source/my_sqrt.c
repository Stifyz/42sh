/*
** my_sqrt.c for Piscine_C_05 in /home/bazin_q/rendu/Piscine_C_J05
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Oct  3 09:52:07 2015 Quentin Bazin
** Last update Sat Dec 05 01:51:18 2015 Quentin Bazin
*/

int	my_sqrt(int nb)
{
  int	a;

  a = 0;
  if (nb <= 0)
    {
      return (0);
    }
  while (a < 46340)
    {
      if (a * a == nb)
	{
	  return (a);
	}
      a = a + 1;
    }
  return (0);
}
