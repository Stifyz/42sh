/*
** autocomplete.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 31 12:13:15 2016 Nicolas Zimmermann
** Last update Thu Jun  2 17:53:39 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <my_printf.h>
#include <stdlib.h>
#include "autocomplete.h"
#include "application.h"

int		autocomplete(t_prompt *prompt)
{
  t_autocomp	autoc;
  int		cnt;

  if (my_strcnt(prompt->line, ' ') == my_strlen(prompt->line))
    return (0);
  autoc.buf = prompt->line;
  list_file(&autoc, prompt->app->path);
  if (!autoc.head)
    return (0);
  sort_list(&autoc);
  if (autoc.head && !autoc.head->next)
    {
      cnt = my_strlen(autoc.head->file_name) - my_strlen(prompt->line);
      free(prompt->line);
      prompt->line = autoc.head->file_name;
      free(autoc.head);
      return (cnt);
    }
  oh_my_42sh(&autoc);
  if (autoc.head)
    my_printf("%s%s", prompt->str, prompt->line);
  free_file_list(&autoc);
  return (0);
}
