/*
** my_showstr.c for Piscine_C_J07 in /home/bazin_q/rendu/Piscine_C_J07/
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Oct  6 11:01:32 2015 Quentin Bazin
** Last update Sun Oct 18 13:16:12 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

int	my_showstr(char *str)
{
  if (str == NULL)
    {
      return (0);
    }
  while (*str != '\0')
    {
      if (!my_is_printable(*str))
	{
	  my_putchar('\\');
	  if (*str < 0x10)
	    {
	      my_putchar('0');
	    }
	  my_putnbr_base(*str, "0123456789abcdef");
	}
      else
	{
	  my_putchar(*str);
	}
      str = str + 1;
    }
  return (0);
}
