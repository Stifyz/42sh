/*
** display_autocomplete_in_line.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/source/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Sat Jun  4 03:37:26 2016 Nicolas Zimmermann
** Last update Sun Jun  5 01:15:19 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <stdlib.h>
#include "autocomplete.h"

t_err    display_autocomplete_in_line(t_autocomp *autoc, t_prompt *prompt)
{
  int	j;

  j = my_strlen(autoc->buf) - 1;
  while (autoc->head->file_name[++j])
    prompt_add_char(prompt, autoc->head->file_name[j]);
  return (0);
}
