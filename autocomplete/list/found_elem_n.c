/*
** found_elem_n.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 18:15:02 2016 Nicolas Zimmermann
** Last update Tue May 31 18:48:30 2016 Nicolas Zimmermann
*/

#include "autocomplete.h"
#include <my.h>

t_file		*found_elem_n(t_autocomp *autoc, int n)
{
  t_file	*tmp;

  tmp = autoc->head;
  while (tmp && tmp->nb != n)
    tmp = tmp->next;
  return (tmp);
}
