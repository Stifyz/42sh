/*
** my_round.c for  in /blinux_home/bazin_q/rendu/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Dec 23 19:08:04 2015 Quentin Bazin
** Last update Wed Dec 23 19:08:04 2015 Quentin Bazin
*/

#include "my.h"

double	my_round(double x)
{
  if (x - (int)x >= 0.5)
    return ((int)x + 1);
  else
    return (x);
}
