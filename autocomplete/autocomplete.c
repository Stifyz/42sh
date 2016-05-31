/*
** autocomplete.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 12:13:15 2016 Nicolas Zimmermann
** Last update Tue May 31 20:00:52 2016 Nicolas Zimmermann
*/

#include "autocomplete.h"

void		autocomplete(char *buf)
{
  t_autocomp	autoc;

  autoc.buf = buf;
  list_file(&autoc);
  sort_list(&autoc);
  oh_my_42sh(&autoc);
  free_file_list(&autoc);
}
