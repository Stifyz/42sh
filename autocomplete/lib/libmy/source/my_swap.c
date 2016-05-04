/*
** my_swap.c for Piscine_C_J04 in /home/bazin_q/rendu/Piscine_C_J04
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Oct  1 09:16:51 2015 Quentin Bazin
** Last update Fri Oct  2 11:54:12 2015 Quentin Bazin
*/

int	my_swap(int *a, int *b)
{
  int	c;

  if (!a || !b)
    {
      return (1);
    }
  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
