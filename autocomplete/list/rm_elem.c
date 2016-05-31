/*
** rm_elem.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 13:19:44 2016 Nicolas Zimmermann
** Last update Tue May 31 14:13:39 2016 Nicolas Zimmermann
*/

#include <stdlib.h>
#include "autocomplete.h"

void	rm_elem(t_file *node, t_autocomp *autoc)
{
  if (node)
    {
      if (node == autoc->head)
	autoc->head = node->next;
      if (node->next)
	node->next->prev = node->prev;
      if (node->prev)
	node->prev->next = node->next;
      free(node->file_name);
      free(node);	    
    }
}
