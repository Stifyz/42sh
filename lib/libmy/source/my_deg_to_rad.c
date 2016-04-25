/*
** my_deg_to_rad.c for  in /blinux_home/bazin_q/rendu/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Dec 23 08:37:37 2015 Quentin Bazin
** Last update Wed Dec 23 08:37:37 2015 Quentin Bazin
*/

#include <math.h>
#include "my.h"

double	my_deg_to_rad(double degrees)
{
  return (degrees / 180.0 * M_PI);
}
