/*
** sort_list.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 11:02:41 2016 Nicolas Zimmermann
** Last update Thu Jun  2 16:05:34 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <stdbool.h>
#include "autocomplete.h"

static int		count_elem(t_autocomp *autoc)
{
  int		i;
  t_file	*tmp;

  i = 0;
  tmp = autoc->head;
  while (tmp)
    {
      i++;
      tmp =tmp->next;
    }
  return (i);
}

void		sort_list(t_autocomp *autoc)
{
  t_file	*tmp;
  int		ret;
  bool		b;

  if (autoc->head)
    {
      b = false;
      while (b == false)
	{
	  b = true;
	  tmp = autoc->head;
	  while (tmp->next)
	    if (!(ret = my_strcmp(tmp->file_name, tmp->next->file_name)))
	      rm_elem(tmp->next, autoc);
	    else if (ret > 0)
	      {
		swap_elem(tmp, tmp->next);
		b = false;
	      }
	    else
	      tmp = tmp->next;
	}
      autoc->nb_elem = count_elem(autoc);
    }
}
