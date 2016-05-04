/*
** my_show_wordtab.c for Piscine_C_J08 in /home/bazin_q/rendu/Piscine_C_J08
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Oct  7 12:00:33 2015 Quentin Bazin
** Last update Thu Oct  8 16:05:45 2015 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>

int		my_show_wordtab(char **tab)
{
  long int	i;

  i = 0;
  if (tab == NULL)
    return (1);
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
  return (0);
}
