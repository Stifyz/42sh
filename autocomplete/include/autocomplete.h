/*
** autocomplete.h for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:49:26 2016 Nicolas Zimmermann
** Last update Tue May 24 17:08:00 2016 Nicolas Zimmermann
*/

#ifndef AUTOCOMPLETE_H_
# define AUTOCOMPLETE_H_

# include <dirent.h>
# include <ncurses.h>

# define NB_PATHES 7
# define MAX_ELEM_PRINTABLE 10

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

void	list_file(t_autocomp *autoc);
void	free_file_list(t_autocomp *autoc);
void	show_file_list(t_autocomp *autoc);

void	oh_my_42sh(t_autocomp *autoc);

#endif /* !AUTOCOMPLETE_H_ */
