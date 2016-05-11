/*
** autocomplete.h for 42sh in /home/zimmer_n/rendu/42sh
** 
** Made by Nicolas Zimmermann
** Login   <zimmer_n@epitech.net>
** 
** Started on  Tue May 10 14:49:26 2016 Nicolas Zimmermann
** Last update Tue May 10 17:05:29 2016 Nicolas Zimmermann
*/

#ifndef AUTOCOMPLETE_H_
# define AUTOCOMPLETE_H_

# include <dirent.h>

# define NB_PATHES 7

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

#endif /* !AUTOCOMPLETE_H_ */
