/*
** OM42sh.c for 42sh in /home/zimmer_n/rendu/PSU_2015_42sh/autocomplete
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 24 16:55:24 2016 Nicolas Zimmermann
** Last update Tue May 31 20:01:16 2016 Nicolas Zimmermann
*/

#include <my.h>
#include <my_printf.h>
#include <unistd.h>
#include "autocomplete.h"

int	check_nb_elem(t_autocomp *autoc)
{
  char	c;

  if (autoc->nb_elem > MAX_ELEM_PRINTABLE)
    {
      my_printf("\nAutocomplete found %d elements beggining by %s\n",
		autoc->nb_elem, autoc->buf);
      while (42)
	{
	  my_printf("Do you want to display all ? <y/n>");
	  read(1, &c, 1);
	  my_putchar('\n');
	  if (c == 'y' || c == 'n')
	    return ((c == 'y') ? 0 : 1);
	}
    }
  return (0);
}

void	oh_my_42sh(t_autocomp *autoc)
{
  if (check_nb_elem(autoc) == 1)
    return ;
  display_autocomplete(autoc);
}
