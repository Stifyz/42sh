/*
** command.h for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 17:56:05 2016 Quentin Bazin
** Last update Wed Mar 30 17:56:05 2016 Quentin Bazin
*/
#ifndef COMMAND_H_
# define COMMAND_H_

# include "error.h"
# include "redirection.h"

struct s_application;

typedef struct		s_argument
{
  char			*str;
  struct s_argument	*next;
}			t_argument;

typedef struct		s_command
{
  t_argument		*args;
  t_argument		*last_arg;
  int			argc;
  char			**argv;
  char			*path;
  int			input_fd;
  int			output_fd;
  t_redirection		*input;
  t_redirection		*output;
  struct s_command	*piped_parent;
  struct s_command	*piped_command;
  struct s_command	*next;
}			t_command;

/* command.c */
t_command	*command_new();
t_err		command_add_argument(t_command *command, char *str);
t_err		command_create_argv(t_command *command);
t_err		command_open_redirections(t_command *command);
/* t_err		command_parse_redirections(t_command *command); */
void		command_free(t_command *command);

/* command_run.c */
t_err	command_setup_pipe(t_command *command);
void	command_close_pipes(t_command *command);
t_err	command_run(t_command *command, struct s_application *app);
void	command_run_program(t_command *, struct s_application *, char **env);

#endif /* !COMMAND_H_ */
