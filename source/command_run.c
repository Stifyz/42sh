/*
** command_run.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Thu Apr 07 18:56:50 2016 Quentin Bazin
** Last update Sat Jun  4 05:58:58 2016 Bouama_r
*/

#include <my.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "application.h"
#include "command.h"
#include "signals.h"

t_err	command_run_fork(t_command *command, t_application *app)
{
  t_err	error;
  char	**env;

  if (command->piped_command || ((error = alias_run(app, command->argv)) == -1 &&
				 !builtin_run(app, command->argv)))
    {
      if (command->piped_command)
	command_setup_pipe(command);
      env = env_to_strarray(app->env);
      command->pid = fork();
      if (command->pid == 0)
	command_run_program(command, app, env);
      else
	{
	  command_close_pipe(command);
	  if (command->piped_command)
	    command_run(command->piped_command, app);
	}
      signals_check_status(app, command);
      my_free_str_array(env);
    }
  return (error > 0 ? error : 0);
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
  if (!command->argv[0])
    return (print_error(ERROR_INVALID_NULL_COMMAND));
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

void	command_redirect_io(t_command *command)
{
  if (command->output_fd != 1)
    {
      close(1);
      dup(command->output_fd);
      close(command->output_fd);
    }
  if (command->input_fd != 0)
    {
      close(0);
      dup(command->input_fd);
      close(command->input_fd);
    }
}

void	command_run_program(t_command *command, t_application *app, char **env)
{
  t_err	error;
  int	exit_code;

  error = 0;
  exit_code = 0;
  if (command_open_redirections(command) ||
      command_prepare_redirections(command))
    exit(1);
  command_redirect_io(command);
  command_close_pipes(command);
  if ((error = alias_run(app, command->argv)) == -1
      && !builtin_run(app, command->argv)
      && (!command->path || execve(command->path, command->argv, env) == -1))
    {
      if (errno == ENOENT || errno == EBADF)
	exit_code = print_error(ERROR_COMMAND_NOT_FOUND, command->argv[0]) && 1;
      else if (errno == ENOEXEC)
	exit_code = print_error(ERROR_EXECVE_FAILED, command->argv[0],
				" Binary file not executable.") && 1;
      else
	exit_code = print_error(ERROR_EXECVE_FAILED, command->argv[0], "") && 1;
    }
  exit(error > 0 ? 1 : exit_code);
}
