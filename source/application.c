/*
** application.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 16:58:29 2016 Quentin Bazin
** Last update Fri Mar 25 16:58:29 2016 Quentin Bazin
*/

#include <ncurses.h>
#include <my.h>
#include <term.h>
#include <unistd.h>
#include "application.h"
#include "lexer.h"
#include "utils.h"

t_err		application_init(t_application *app, char **env)
{
  char		*path;

  my_memset(app, 0, sizeof(t_application));
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
  /* my_memset(&app->parser, 0, sizeof(t_parser)); #<{(| FIXME: Is it needed? |)}># */
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
	    print_error(ERROR_SYNTAX_ERROR, first_invalid_char);
	  else
	    line = application_run_command(app, line);
	  free(line);
	}
      else
	app->is_running = false;
      if (!app->is_running && isatty(0) && isatty(1))
	my_putstr("exit\n");
    }
}

void	application_test_lexer(char *cmd)
{
  t_string_reader	reader;
  t_token_list		list;

  my_memset(&list, 0, sizeof(t_token_list));
  reader.string = cmd;
  reader.length = my_strlen(cmd);
  reader.pos = 0;
  lexer_fill_token_list(&reader, &list);
  token_list_print(&list);
  token_list_free(&list);
}

char	*application_run_command(t_application *app, char *cmd)
{
  t_command	*tmp;

  /* application_test_lexer(cmd); #<{(| FIXME: TO REMOVE |)}># */
  cmd = my_epur_str(cmd);
  if (cmd[0] != '\0' && (cmd[0] != ' ' || cmd[1] != '\0'))
    {
      if (parser_parse_str(&app->parser, app, cmd))
	{
	  return (cmd);
	}
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
  if (isatty(0) && isatty(1))
    my_putstr(tigetstr("rmkx"));
}
