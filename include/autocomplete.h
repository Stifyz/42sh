/*
** autocomplete.h for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:49:26 2016 Nicolas Zimmermann
** Last update Sun Jun  5 21:21:32 2016 Nicolas Zimmermann
*/

#ifndef AUTOCOMPLETE_H_
# define AUTOCOMPLETE_H_

# define MAX_ELEM_PRINTABLE 50
# define MARGE 3

#include <stddef.h>
# include "error.h"
# include "prompt.h"

typedef	struct	s_file
{
  char		*file_name;
  int		len;
  struct s_file	*next;
  struct s_file *prev;
}		t_file;

typedef struct	s_autocomp
{
  int		nb_elem;
  bool		is_file;
  char		*buf;
  t_file	*head;
}		t_autocomp;

t_err	autocomplete(t_prompt *prompt);
t_err   autocomplete_file(char *arg, t_autocomp *autoc);
t_err	autocomplete_cmd(char *arg, t_autocomp *autoc, char **pathes);

t_err	file_list(t_autocomp *autoc, char **pathes);
void	free_file_list(t_autocomp *autoc);
void	swap_elem(t_file *node1, t_file *node2);
void	rm_elem(t_file *node, t_autocomp *autoc);
void	sort_list(t_autocomp *autoc);

t_err	oh_my_42sh(t_autocomp *autoc, t_prompt *prompt);
void	display_autocomplete(t_autocomp *autoc);
t_err	display_autocomplete_in_line(t_autocomp *autoc, t_prompt *prompt);

void	my_getmaxyx(int *y, int *x);

#endif /* !AUTOCOMPLETE_H_ */
