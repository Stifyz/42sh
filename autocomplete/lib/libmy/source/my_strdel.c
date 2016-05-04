/*
** my_strdel.c for  in /blinux_home/bazin_q/rendu/Piscine_C_bistromathique
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 01 18:48:12 2015 Quentin Bazin
** Last update Sun Nov 01 18:53:28 2015 Quentin Bazin
*/

#include "my.h"

char	*my_strdel(char *str, int nb)
{
  int	i;
  int	j;

  j = 0;
  if (nb > 0)
    {
      i = nb;
      while (str[i] != '\0')
	{
	  str[j] = str[i];
	  j = j + 1;
	  i = i + 1;
	}
      str[j] = '\0';
    }
  else
    {
      i = my_abs(nb);
      str[my_strlen(str) - my_abs(nb)] = '\0';
    }
  return (str);
}
