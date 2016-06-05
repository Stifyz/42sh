/*
** application.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
**
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
**
** Started on  Fri Mar 25 16:58:29 2016 Quentin Bazin
** Last update Sat Jun  4 06:20:39 2016 Bouama_r
*/

#include <ncurses.h>
#include <my.h>
#include <my_printf.h>
#include <signal.h>
#include <term.h>
#include <unistd.h>
#include "lexer.h"
#include "signals.h"
#include "utils.h"

t_err		application_init(t_application *app, char **env)
{
  char		*path;

  my_memset(app, 0, sizeof(t_application));
  signal(SIGINT, signals_handle_sigint);
  if (!(app->env = env_init(env)) && env[0])
    return (print_error(ERROR_MALLOC_FAILED));
  if (!(path = my_getenv(app->env, "PATH")))
    path = "/bin:/usr/bin";
  if (!(app->path = my_str_to_array(path, ":")))
    return (print_error(ERROR_MALLOC_FAILED));
  if ((!my_getenv(app->env, "TERM") && setterm("xterm-noapp") != OK) ||
      (my_getenv(app->env, "TERM") && setterm(NULL) != OK))
    return (print_error(ERROR_SETTERM_FAILED));
  builtin_init_array(app);
  app->is_running = true;
  if (isatty(0) && isatty(1))
    my_putstr(tigetstr("smkx"));
  return (prompt_init(&app->prompt, app));
}

void		application_run(t_application *app)
{
  char	*line;
  int	first_invalid_char;

  while (app->is_running)
    {
      if (isatty(0) && isatty(1))
	my_putstr(app->prompt.str);
      if ((isatty(0) && (line = prompt_read_line(&app->prompt)) != NULL) ||
	  (!isatty(0) && (line = my_getline(0))))
	{
	  if ((first_invalid_char = my_cmd_isvalid(line)) != -1)
	    {
	      print_error(ERROR_SYNTAX_ERROR, first_invalid_char);
	      free(line);
	    }
	  else
	    application_run_command(app, line);
	}
      else
	app->is_running = false;
      if (!app->is_running && isatty(0) && isatty(1))
	my_putstr("exit\n");
    }
}

void		application_parse(t_application *app, t_token_list *token_list)
{
  t_command	*tmp;
  t_parser	parser;

  my_memset(&parser, 0, sizeof(t_parser));
  parser.current = token_list->first;
  if (!parse(&parser))
    {
      tmp = parser.full_command;
      while (tmp)
	{
	  command_run(tmp, app);
	  tmp = tmp->next;
	}
      command_free(parser.full_command);
    }
  else
    app->exit_code = 1;
}

void			application_run_command(t_application *app, char *cmd)
{
  t_string_reader	reader;
  t_token_list		token_list;

  my_memset(&token_list, 0, sizeof(t_token_list));
  reader.string = cmd;
  reader.length = my_strlen(cmd);
  reader.pos = 0;
  if (!lexer_fill_token_list(&reader, &token_list))
    {
      free(cmd);
      if (app->prompt.line)
	app->prompt.line = NULL;
      application_parse(app, &token_list);
    }
  token_list_free(&token_list);
}

void		application_free(t_application *app)
{
  env_free(app->env);
  my_free_str_array(app->path);
  free(app->cd_history);
  if (isatty(0) && isatty(1))
    my_putstr(tigetstr("rmkx"));
}
