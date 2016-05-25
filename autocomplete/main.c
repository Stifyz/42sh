/*
** main.c for  in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 15:48:06 2016 Nicolas Zimmermann
** Last update Wed May 25 20:46:17 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "autocomplete.h"

int	main(int ac, char **av)
{
  t_autocomp	autoc;

  if (ac > 1)
    {
      autoc.buf = av[1];
      list_file(&autoc);
      oh_my_42sh(&autoc);
      my_putstr("\n\n");
      show_file_list(&autoc);
      free_file_list(&autoc);
    }
  return (0);
}
