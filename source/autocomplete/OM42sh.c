/*
** OM42sh.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 24 16:55:24 2016 Nicolas Zimmermann
** Last update Thu Jun  2 18:19:34 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <my_printf.h>
#include <unistd.h>
#include "autocomplete.h"
#include "utils.h"

int	check_nb_elem(t_autocomp *autoc)
{
  char	c;

  if (autoc->nb_elem > MAX_ELEM_PRINTABLE)
    {
      my_printf("\nAutocomplete found %d elements beggining by \"%s\"\n",
		autoc->nb_elem, autoc->buf);
      my_printf("Do you want to display all ? <y/n>");
      while (42)
	{
	  c = my_getch();
	  if (c == 'y' || c == 'n')
	    return ((c == 'y') ? 0 : 1);
        }
    }
  return (0);
}

void	oh_my_42sh(t_autocomp *autoc)
{
  if (!autoc->head || check_nb_elem(autoc) == 1)
    {
      my_putchar('\n');
      return ;
    }
  display_autocomplete(autoc);
}
