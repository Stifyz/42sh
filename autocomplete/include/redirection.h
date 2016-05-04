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

/*
** Check if an argument is a redirection
*/
# define IS_IRED(arg) (arg[0] == '<' && (!arg[1] || (arg[1] == '<' && !arg[2])))
# define IS_ORED(arg) (arg[0] == '>' && (!arg[1] || (arg[1] == '>' && !arg[2])))
# define IS_DRED(arg) (arg[1] == '>' || arg[1] == '<')
# define IS_VRED(arg) (my_strlen(arg) == 1 || my_strlen(arg) == 2)

/*
** Get io mode
*/
# define GET_IO_MODE1(arg) (IS_ORED(arg) ? IO_MODE_OUTPUT : IO_MODE_INPUT)
# define GET_IO_MODE2(arg) (IS_DRED(arg) ? IO_MODE_DOUBLE : IO_MODE_SIMPLE)
# define GET_IO_MODE3(arg) (GET_IO_MODE1(arg) | GET_IO_MODE2(arg))
# define GET_IO_MODE(arg) (IS_VRED(arg) ? GET_IO_MODE3(arg) : 0)

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
