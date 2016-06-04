/*
** redirection.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Apr 02 13:50:42 2016 Quentin Bazin
** Last update Sat Apr 02 13:50:42 2016 Quentin Bazin
*/
#ifndef REDIRECTION_H_
# define REDIRECTION_H_

# include "error.h"

struct s_command;

typedef enum		e_io_mode
{
  IO_MODE_INPUT		= 1,
  IO_MODE_OUTPUT	= 2,
  IO_MODE_SIMPLE	= 4,
  IO_MODE_DOUBLE	= 8
}			t_io_mode;

typedef struct		s_redirection
{
  char			*filepath;
  int			open_flags;
  t_io_mode		mode;
  char			*data;
}			t_redirection;

t_redirection	*redirection_new(char *filepath, t_io_mode mode);
t_err		redirection_check(t_redirection *redirection);
void		redirection_free(t_redirection *redirection);

#endif /* !REDIRECTION_H_ */
