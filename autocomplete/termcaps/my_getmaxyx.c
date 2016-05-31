/*
** my_getmaxyx.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Wed May 25 18:57:55 2016 Nicolas Zimmermann
** Last update Sat May 28 17:02:14 2016 Nicolas Zimmermann
*/

#include <sys/ioctl.h>
#include "pos.h"

void			my_getmaxyx(t_pos *pos)
{
  struct winsize	w;

  ioctl(0, TIOCGWINSZ, &w);
  pos->x = w.ws_row;
  pos->y = w.ws_col;
}
