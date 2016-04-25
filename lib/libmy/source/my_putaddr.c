/*
** my_putaddr.c for  in /blinux_home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Jan 07 19:32:44 2016 Quentin Bazin
** Last update Thu Jan 07 19:32:44 2016 Quentin Bazin
*/

#include <my.h>

void	my_putaddr(void *ptr)
{
  my_putstr("0x");
  my_putnbr_base((long int)ptr, "0123456789abcdef");
}
