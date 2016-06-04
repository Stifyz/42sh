/*
** command_pipe.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Jun 04 20:52:37 2016 Quentin Bazin
** Last update Sat Jun 04 20:52:37 2016 Quentin Bazin
*/

#include <unistd.h>
#include "command.h"

void	command_init_pipe(t_command *command)
{
  command->piped_command->input_fd = -1;
  command->piped_command->piped_parent = command;
  command->output_fd = -1;
}

t_err	command_setup_pipe(t_command *command)
{
  int	pipe_fd[2];

  if (pipe(pipe_fd) == -1)
    return (print_error(ERROR_PIPE_FAILED));
  command->piped_command->input_fd = pipe_fd[0];
  command->piped_command->piped_parent = command;
  command->output_fd = pipe_fd[1];
  return (0);
}

void		command_close_pipes(t_command *command)
{
  while (command->piped_parent)
    command = command->piped_parent;
  while (command)
    {
      if (command->input_fd > 2)
	{
	  close(command->input_fd);
	  command->input_fd = -1;
	}
      if (command->output_fd > 2)
	{
	  close(command->output_fd);
	  command->output_fd = -1;
	}
      command = command->piped_command;
    }
}
