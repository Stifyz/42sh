/*
** swap_elem.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 11:04:54 2016 Nicolas Zimmermann
** Last update Tue May 31 18:58:56 2016 Nicolas Zimmermann
*/

#include "autocomplete.h"

void		swap_elem(t_file *node1, t_file *node2)
{
  void		*tmp;

  tmp = node1->file_name;
  node1->file_name = node2->file_name;
  node2->file_name = tmp;
}
