/*
** my_basename.c for  in /home/bazin_q/rendu/MyLibs/libmy/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Mar 15 13:06:42 2016 Quentin Bazin
** Last update Tue Mar 15 13:06:42 2016 Quentin Bazin
*/

#include <my.h>
#include <stddef.h>

char	*my_basename(char *path)
{
  char	*basename;

  basename = path;
  if (!path)
    return (NULL);
  while (my_strchr(basename + 1, '/') != NULL)
    basename = my_strchr(basename + 1, '/');
  return ((*basename == '/') ? basename + 1 : basename);
}
