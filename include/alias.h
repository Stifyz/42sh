/*
** alias.h for 42sh in /home/bouamar/rendu/PSU_2015_42sh/include
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Sat Jun  4 01:46:52 2016 Bouama_r
** Last update Sun Jun  5 14:32:59 2016 Nicolas Zimmermann
*/

#ifndef ALIAS_H_
# define ALIAS_H_

/*
**Include
*/

# include <stdbool.h>
# include <stdlib.h>
# include "error.h"

/*
**Structure
*/

struct s_application;

typedef struct		s_alias
{
  char			*name;
  char			*cmd;
  struct s_alias	*next;
}			t_alias;

/*
**Fucntion
*/

t_alias		*search_alias(struct s_application *app, char **av);
t_err		alias_run(struct s_application *app, char **av);
t_alias		*alias_new(char *name, char *cmd);
t_err		builtin_alias(struct s_application *app, int ac, char **av);
int		check_print_alias(struct s_application *app, int ac, char **av);
void		print_alias_info(struct s_application *app, char **av);
t_err		attribution(struct s_application *app, char *name, char *cmd);

#endif /* !ALIAS_H_ */
