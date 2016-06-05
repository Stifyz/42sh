/*
** test.h for test in /home/bouamar/rendu/test
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 23:20:35 2016 Bouama_r
** Last update Sun Jun  5 18:17:54 2016 Nicolas Zimmermann
*/
#ifndef ECHO_H_
# define ECHO_H_

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "application.h"
# include "error.h"

t_err	builtin_echo(t_application *app, int ac, char **av);
void	disp_normal(char **av, int bf);
char	get_escaped_char(char *str, int pos);
void	flag_e(char **av, int bf);
int	my_flag_echo(int ac, char **av);
bool	my_is_octal(char c);
int	check_space(char *str);
int	treat_echo(int ac, char **av, int bf, int b);

#endif /* !ECHO_H_ */
