/*
** get_elem_nb.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Wed May 25 19:39:20 2016 Nicolas Zimmermann
** Last update Wed May 25 19:41:08 2016 Nicolas Zimmermann
*/

#include "autocomplete.h"

t_file		*get_elem_nb(t_autocomp *autoc, int n)
{
  t_file	*tmp;
  int		i;

  tmp = autoc->head;
  i = -1;
  while (++i < n)
    tmp = tmp->next;
  return (tmp);
}
