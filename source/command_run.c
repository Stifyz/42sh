/*
** command_run.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Thu Apr 07 18:56:50 2016 Quentin Bazin
** Last update Thu Apr 07 18:56:50 2016 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "application.h"
#include "command.h"
#include "signals.h"

t_err	command_run_fork(t_command *command, t_application *app)
{
  pid_t	fork_pid;
  char	**env;

  if (command->piped_command || !builtin_run(app, command->argv))
    {
      env = env_to_strarray(app->env);
      fork_pid = fork();
      if (fork_pid == 0)
	command_run_program(command, app, env);
      else if (command->piped_command)
	{
	  command_run(command->piped_command, app);
	  command_close_pipes(command);
	}
      signals_check_status(app);
      my_free_str_array(env);
    }
  return (0);
}

t_err	command_run(t_command *command, t_application *app)
{
  t_err	error;

  if (app->exit_code != 0 && command->condition == CONDITION_AND)
    return (0);
  if (app->exit_code == 0 && command->condition == CONDITION_OR)
    return (0);
  if ((error = command_create_argv(command)))
    return (error);
  if (!command->piped_parent)
    app->exit_code = 0;
  redirection_check(command->input);
  command->path = env_get_prog_path(app->path, command->argv[0]);
  return (command_run_fork(command, app));
}

t_err	command_prepare_redirections(t_command *command)
{
  int	pipe_fd[2];

  if (command->input && (command->input->mode & IO_MODE_DOUBLE))
    {
      if (pipe(pipe_fd) == -1)
	return (print_error(ERROR_PIPE_FAILED));
      command->input_fd = pipe_fd[0];
      write(pipe_fd[1], command->input->data, my_strlen(command->input->data));
      close(pipe_fd[1]);
    }
  return (0);
}

void	command_run_program(t_command *command, t_application *app, char **env)
{
  int	exit_code;

  exit_code = 0;
  if (command_open_redirections(command) ||
      command_prepare_redirections(command))
    exit(1);
  dup2(command->output_fd, 1);
  dup2(command->input_fd, 0);
  command_close_pipes(command);
  if (!builtin_run(app, command->argv)
      && (!command->path || execve(command->path, command->argv, env) == -1))
    {
      exit_code = 1;
      print_error(ERROR_COMMAND_NOT_FOUND, command->argv[0]);
    }
  exit(exit_code);
}
