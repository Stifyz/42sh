/*
** main.c for  in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 15:48:06 2016 Nicolas Zimmermann
** Last update Tue May 31 12:50:27 2016 Nicolas Zimmermann
*/

#include <my.h>
#include "autocomplete.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    autocomplete(av[1]);
  return (0);
}
