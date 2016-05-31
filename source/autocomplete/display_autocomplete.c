/*
** display_autocomplete.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 10:41:30 2016 Nicolas Zimmermann
** Last update Tue May 31 19:51:46 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <my_printf.h>
#include "autocomplete.h"

int		found_max_len(t_autocomp *autoc)
{
  int		max_len;
  t_file	*tmp;

  tmp = autoc->head;
  max_len = 0;
  while (tmp)
    {
      max_len = (tmp->len > max_len) ? tmp->len : max_len;
      tmp = tmp->next;
    }
  return (max_len);
}

void		display_autocomplete(t_autocomp *autoc)
{
  t_file	*tmp;
  int		max_cols;
  int		max_len;
  int		i;
  int		cnt;

  my_getmaxyx(&max_cols, NULL);
  max_len = found_max_len(autoc) + 2;
  tmp = autoc->head;
  while (tmp)
    {
      i = 0;
      while (1)
	{
	  cnt = my_printf("%s", tmp->file_name);
	  tmp = tmp->next;
	  if (!tmp || i++ >= (max_cols / max_len - 1))
	    break ;
	  while (cnt++ < max_len)
	    my_putchar(' ');
	}
      my_putchar('\n');
    }
}
