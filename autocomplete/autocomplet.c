/*
** autocomplet.c for test in /home/audet_b/42sh/test/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Wed Apr 20 16:22:04 2016 Benjamin Audet
** Last update Fri Apr 29 15:36:11 2016 Benjamin Audet
*/

#include <string.h>
#include "list.h"
#include "my.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

char	*my_getline(const int fd);

int	main(int ac, char **av)
{
  (void)ac;
  (void)av;
  t_list	list;

  manage_list(&list);
  display_list(&list);
  free_list(&list);
  return (0);
}
