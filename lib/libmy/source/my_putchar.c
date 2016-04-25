/*
** my_putchar.c for Piscine_C_J03 in /home/bazin_q/rendu
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Sep 30 22:14:53 2015 Quentin Bazin
** Last update Tue Oct  6 10:54:25 2015 Quentin Bazin
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putnchar(char c, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      write(1, &c, 1);
      ++i;
    }
}
