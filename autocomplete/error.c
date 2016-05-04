/*
** error.c for error in /home/audet_b/Downloads/mini/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Fri Apr 29 12:23:26 2016 Benjamin Audet
** Last update Fri Apr 29 12:24:45 2016 Benjamin Audet
*/

#include "list.h"
#include "my.h"

void	error_opendir()
{
  my_putstr("Error opendir\n");
  exit(1);
}

void	error_readdir()
{
  my_putstr("Error readdir\n");
  exit(1);
}
