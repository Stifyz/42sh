/*
** autocomplete.h for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:49:26 2016 Nicolas Zimmermann
** Last update Tue May 31 20:13:53 2016 Nicolas Zimmermann
*/

#ifndef AUTOCOMPLETE_H_
# define AUTOCOMPLETE_H_

# include <dirent.h>
# include <ncurses.h>
# include "pos.h"

# define NB_PATHES 7
# define MAX_ELEM_PRINTABLE 50
# define MARGE 3

typedef	struct	s_file
{
  char		*file_name;
  int		len;
  struct s_file	*next;
  struct s_file *prev;
}	       	t_file;

typedef struct 	s_autocomp
{
  int		nb_elem;
  char		*buf;
  t_file	*head;
}      		t_autocomp;

void	autocomplete(char *buf);

void	list_file(t_autocomp *autoc);
void	free_file_list(t_autocomp *autoc);

void	swap_elem(t_file *node1, t_file *node2);
void	rm_elem(t_file *node, t_autocomp *autoc);

void	sort_list(t_autocomp *autoc);

void	oh_my_42sh(t_autocomp *autoc);
void	display_autocomplete(t_autocomp *autoc);

void	my_getmaxyx(int *y, int *x);

#endif /* !AUTOCOMPLETE_H_ */
