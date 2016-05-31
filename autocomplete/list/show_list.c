/*
** show_list.c for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 15:46:33 2016 Nicolas Zimmermann
** Last update Tue May 31 19:11:28 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "autocomplete.h"

void		show_file_list(t_autocomp *autoc)
{
  t_file	*tmp;

  tmp = autoc->head;
  while ((tmp))
    {
      my_putstr(tmp->file_name);
      my_putchar(' ');
      my_put_nbr(tmp->nb);
      my_putchar('\n');
      tmp = tmp->next;
    }
}
