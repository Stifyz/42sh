/*
** my_str_array_len.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Apr 13 12:54:12 2016 Quentin Bazin
** Last update Wed Apr 13 12:54:12 2016 Quentin Bazin
*/

#include "my.h"

int	my_str_array_len(char **array)
{
  int	i;

  i = 0;
  while (array && array[i])
    ++i;
  return (i);
}
