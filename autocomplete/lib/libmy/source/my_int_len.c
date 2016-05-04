/*
** my_int_len.c for  in /home/bazin_q/rendu/Piscine_C_bistromathique/lib/my
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Oct 31 18:32:07 2015 Quentin Bazin
** Last update Sat Oct 31 18:32:30 2015 Quentin Bazin
*/

#include "my.h"

unsigned int	my_int_len(int n)
{
  unsigned int	k;

  k = my_abs(n);
  if (k > 9)
    {
      return (1 + my_int_len(k / 10));
    }
  else
    {
      return (1);
    }
}
