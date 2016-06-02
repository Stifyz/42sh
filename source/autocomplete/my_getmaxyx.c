/*
** my_getmaxyx.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Wed May 25 18:57:55 2016 Nicolas Zimmermann
** Last update Thu Jun  2 16:07:19 2016 Nicolas Zimmermann
*/

#include <sys/ioctl.h>

void			my_getmaxyx(int *y, int *x)
{
  struct winsize	w;

  ioctl(0, TIOCGWINSZ, &w);
  if (x)
    *x = w.ws_row;
  if (y)
    *y = w.ws_col;
}
