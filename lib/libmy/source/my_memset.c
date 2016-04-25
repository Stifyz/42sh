/*
** my_memset.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Mar 14 17:24:23 2016 Quentin Bazin
** Last update Mon Mar 14 17:24:23 2016 Quentin Bazin
*/

#include <my.h>

void		*my_memset(void *ptr, char c, size_t n)
{
  size_t	i;
  char		*p;

  i = 0;
  if (ptr == NULL)
    return (NULL);
  p = ptr;
  while (i < n)
    {
      p[i] = c;
      ++i;
    }
  return (ptr);
}
