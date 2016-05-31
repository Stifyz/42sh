/*
** free_list.c for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 15:41:40 2016 Nicolas Zimmermann
** Last update Tue May 31 12:06:35 2016 Nicolas Zimmermann
*/

#include <stdlib.h>
#include "autocomplete.h"

void		free_file_list(t_autocomp *autoc)
{
  t_file	*tmp[2];

  tmp[0] = autoc->head;
  while (tmp[0])
    {
      tmp[1] = tmp[0]->next;
      free(tmp[0]->file_name);
      free(tmp[0]);
      tmp[0] = tmp[1];
    }
}
