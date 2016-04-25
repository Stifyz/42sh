/*
** my_itos.c for  in /home/bazin_q/rendu/Piscine_C_bistromathique/lib/my
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Oct 31 18:20:25 2015 Quentin Bazin
** Last update Sat Oct 31 18:31:13 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

char		*my_itos(int nb)
{
  char		*result;
  int		i;
  unsigned int	n;

  if ((result = malloc(my_int_len(nb) + 1)) == NULL)
    {
      return (NULL);
    }
  result[my_int_len(nb)] = '\0';
  i = my_int_len(nb);
  n = my_abs(nb);
  while ((i = i - 1) >= 0)
    {
      result[i] = '0' + n % 10;
      if (n > 9)
	{
	  n = n / 10;
	}
    }
  if (nb < 0)
    {
      my_strins(result, '-', 0);
    }
  return (result);
}

