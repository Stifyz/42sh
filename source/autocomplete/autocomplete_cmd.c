/*
** autocomplete_cmd.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/source/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Sat Jun  4 04:09:46 2016 Nicolas Zimmermann
** Last update Sun Jun  5 21:21:20 2016 Nicolas Zimmermann
*/

#include "autocomplete.h"

t_err	autocomplete_cmd(char *arg, t_autocomp *autoc, char **pathes)
{
  autoc->buf = arg;
  return (file_list(autoc, pathes));
}
