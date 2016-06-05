/*
** signals.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Mar 26 10:53:23 2016 Quentin Bazin
** Last update Sat Mar 26 10:53:23 2016 Quentin Bazin
*/

#include <my.h>
#include <sys/wait.h>
#include "signals.h"

void	check_exit_code(t_application *app, int status)
{
  if (WIFEXITED(status) && !app->exit_code)
    app->exit_code = WEXITSTATUS(status);
  else if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	{
	  my_puterr("Segmentation fault");
	  if (WCOREDUMP(status))
	    my_puterr(" (core dumped)");
	  my_puterr("\n");
	  app->exit_code = 128 + SIGSEGV;
	}
      else if (WTERMSIG(status) == SIGFPE)
	{
	  my_puterr("Floating exception");
	  if (WCOREDUMP(status))
	    my_puterr(" (core dumped)");
	  my_puterr("\n");
	  app->exit_code = 128 + SIGFPE;
	}
    }
}

void		signals_check_status(t_application *app, t_command *command)
{
  int		status;
  t_command	*tmp;

  tmp = command;
  status = 0;
  while (tmp->piped_parent)
    tmp = tmp->piped_parent;
  while (tmp && waitpid(tmp->pid, &status, WUNTRACED))
    {
      if (command->piped_command)
	command_close_pipe(command);
      check_exit_code(app, status);
      tmp = tmp->piped_command;
    }
}
