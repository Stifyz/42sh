/*
** display_autocomplete.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete/OM42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Wed May 25 18:37:49 2016 Nicolas Zimmermann
** Last update Wed May 25 20:46:32 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <my_printf.h>
#include <stdlib.h>
#include <unistd.h>
#include "autocomplete.h"

int		found_nb_colums(t_autocomp *autoc, t_aff *aff)
{
  t_file	*tmp;
  int		i;
  int		j;
  int		k;

  if (!(aff->max_len = malloc(sizeof(int) * (aff->nb_cols + 1))))
    exit (0);
  i = -1;
  while (++i < aff->nb_cols)
    aff->max_len[i] = 0;
  tmp = autoc->head;
  my_getmaxyx(&aff->max);
  i = -1;
  while (++i < aff->nb_cols)
    {
      j = -1;
      while (++j < autoc->nb_elem / aff->nb_cols)
	{
	  if (my_strlen(tmp->file_name) > aff->max_len[i])
	    aff->max_len[i] = my_strlen(tmp->file_name);
	  tmp = tmp->next;
	}
      aff->max_len[aff->nb_cols] = 0;
      k = -1;
      while (++k < aff->nb_cols)
	aff->max_len[aff->nb_cols] += aff->max_len[k];
      if (aff->max_len[aff->nb_cols] > aff->max.x)
	return (-1);
    }
  return (0);
}

void		display_autocomplete(t_autocomp *autoc)
{
  t_aff		aff;
  t_pos		pos;
  int		i;

  aff.nb_cols = NB_COLS_MAX;
  while ((aff.nb_cols) && found_nb_colums(autoc, &aff) == -1)
    {
      free(aff.max_len);
      aff.nb_cols--;
    }
  if (!aff.nb_cols)
    {
      write(2, "Cannot display, one of the arguments is too long for your term.\n", 64);
      free(aff.max_len);
      return ;
    }
  pos.y = -1;
  while (++pos.y < autoc->nb_elem / aff.nb_cols)
    {
      pos.x = -1;
      while (++pos.x < aff.nb_cols)
	{
	  i = my_printf("%s", get_elem_nb(autoc, (autoc->nb_elem / aff.nb_cols * pos.y + pos.x))->file_name);
	  while (i++ < aff.max_len[pos.x])
	    my_putchar(' ');
	}
    }
  free(aff.max_len);
  my_putstr("----------------------");
}
