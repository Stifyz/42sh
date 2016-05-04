/*
** my_putstr.c for Piscine_C_J04 in /home/bazin_q/rendu/Piscine_C_J04
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Oct  1 09:45:50 2015 Quentin Bazin
** Last update Wed Dec 09 15:53:07 2015 Quentin Bazin
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(const char *str)
{
  int	i;

  i = 0;
  if (!str)
    return (1);
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      ++i;
    }
  return (0);
}

void	my_puterr(const char *str)
{
  write(2, str, my_strlen(str));
}
