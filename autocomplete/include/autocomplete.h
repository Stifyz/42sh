/*
** autocomplete.h for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:49:26 2016 Nicolas Zimmermann
** Last update Wed May 25 19:31:27 2016 Nicolas Zimmermann
*/

#ifndef AUTOCOMPLETE_H_
# define AUTOCOMPLETE_H_

# include <dirent.h>
# include <ncurses.h>
# include "pos.h"

# define NB_PATHES 7
# define MAX_ELEM_PRINTABLE 10
# define NB_COLS_MAX 4

typedef	struct	s_file
{
  char		*file_name;
  struct s_file	*next;
}	       	t_file;

typedef struct 	s_autocomp
{
  int		nb_elem;
  char		*buf;
  t_file	*head;
}      		t_autocomp;

typedef struct	s_aff
{
  t_pos		max;
  int		nb_cols;
  int		*max_len;
}		t_aff;

void	list_file(t_autocomp *autoc);
void	free_file_list(t_autocomp *autoc);
void	show_file_list(t_autocomp *autoc);

t_file	*get_elem_nb(t_autocomp *autoc, int n);

void	oh_my_42sh(t_autocomp *autoc);
void	display_autocomplete(t_autocomp *autoc);

void	my_getmaxyx(t_pos *pos);

#endif /* !AUTOCOMPLETE_H_ */
