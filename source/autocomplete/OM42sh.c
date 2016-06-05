/*
** OM42sh.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 24 16:55:24 2016 Nicolas Zimmermann
** Last update Sun Jun  5 03:46:31 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <my_printf.h>
#include <stddef.h>
#include <unistd.h>
#include "autocomplete.h"
#include "utils.h"

int	check_nb_elem(t_autocomp *autoc)
{
  if (autoc->nb_elem > MAX_ELEM_PRINTABLE)
    {
      my_printf("\nAutocomplete found %d elements", autoc->nb_elem);
      if (autoc->buf)
	my_printf(" beggining by \"%s\"\n", autoc->buf);
      else
	my_putchar('\n');
      my_printf("Do you want to display all of them? [y/N]");
      return ((my_getch() == 'y') ? 0 : write(1, "\n", 1));
    }
  return (0);
}

t_err	oh_my_42sh(t_autocomp *autoc, t_prompt *prompt)
{
  if (!autoc->head)
    return (0);
  else if (!autoc->head->next)
    return (display_autocomplete_in_line(autoc, prompt));
  else
    {
      if (check_nb_elem(autoc) == 0)
	display_autocomplete(autoc);
      my_printf("%s%s", prompt->str, prompt->line);
    }
  return (0);
}
