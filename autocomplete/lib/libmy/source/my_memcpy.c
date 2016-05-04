/*
** my_memcpy.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Mar 19 14:11:42 2016 Quentin Bazin
** Last update Sat Mar 19 14:11:42 2016 Quentin Bazin
*/

#include <my.h>

void		*my_memcpy(void *dest, void *src, size_t n)
{
  size_t	i;
  char		*destp;
  char		*srcp;

  i = 0;
  destp = dest;
  srcp = src;
  while (i < n)
    {
      destp[i] = srcp[i];
      ++i;
    }
  return (dest);
}
