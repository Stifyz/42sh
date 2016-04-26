/*
** application.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 16:58:29 2016 Quentin Bazin
** Last update Fri Mar 25 16:58:29 2016 Quentin Bazin
*/

#include <my.h>
#include <my_printf.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "application.h"
#include "signals.h"
#include "utils.h"

t_err		application_init(t_application *app, char **env)
{
  my_memset(app, 0, sizeof(t_application));
  if (!(app->env = env_init(env)) ||
      !(app->path = my_str_to_array(my_getenv(app->env, "PATH"), ":")))
    return (print_error(ERROR_MALLOC_FAILED));
  builtin_init_array(app);
  my_memset(&app->parser, 0, sizeof(t_parser));
  app->is_running = true;
  return (0);
}

void		application_run(t_application *app)
{
  char	*line;

  while (app->is_running)
    {
      if (isatty(1))
	my_putstr("> ");
      if ((line = my_getline(0)) != NULL)
	{
	  if (!my_cmd_isvalid(line))
	    print_error(ERROR_SYNTAX_ERROR);
	  else
	    line = application_run_command(app, line);
	  free(line);
	}
      else
	app->is_running = false;
      if (!app->is_running && isatty(1))
	my_putstr("exit\n");
    }
}

char	*application_run_command(t_application *app, char *cmd)
{
  t_command	*tmp;

  cmd = my_epur_str(cmd);
  if (cmd[0] != '\0' && (cmd[0] != ' ' || cmd[1] != '\0'))
    {
      if (parser_parse_str(&app->parser, app, cmd))
	return (cmd);
      tmp = app->parser.commands;
      while (tmp)
	{
	  command_run(tmp, app);
	  tmp = tmp->next;
	}
      command_free(app->parser.commands);
      my_memset(&app->parser, 0, sizeof(t_parser));
    }
  return (cmd);
}

void		application_free(t_application *app)
{
  env_free(app->env);
  my_free_str_array(app->path);
  free(app->cd_history);
}
