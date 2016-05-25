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
#include "lexer.h"
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

#include <asm-generic/ioctls.h>
#include <stropts.h>
#include <termios.h>
#include <unistd.h>

char			my_getch()
{
  struct termios	old_t;
  struct termios	new_t;
  char			c;

  ioctl(0, TCGETS, &old_t);
  new_t = old_t;
  new_t.c_lflag &= ~(ECHO | ICANON);
  ioctl(0, TCSETS, &new_t);
  if (read(0, &c, 1) == 0)
    return (-1);
  ioctl(0, TCSETS, &old_t);
  return (c);
}

char		*read_line()
{
  char		*line;
  char		c;

  line = NULL;
  while ((c = my_getch()) != -1 && c != '\n' && c != '\r')
    {
      if (c == 127)
	{
	  line[my_strlen(line) - 1] = '\0';
	  my_putstr("\b \b");
	}
      else
	{
	  line = my_strncatm(line, &c, 1);
	  my_putchar(c);
	}
    }
  my_putstr("\n");
  return (line);
}

void		application_run(t_application *app)
{
  char	*line;
  int	first_invalid_char;

  while (app->is_running)
    {
      if (isatty(1))
	my_putstr("> ");
      if ((line = read_line()) != NULL)
	{
	  if ((first_invalid_char = my_cmd_isvalid(line)) != -1)
	    print_error(ERROR_SYNTAX_ERROR, first_invalid_char);
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

  /* application_test_lexer(cmd); FIXME: TO REMOVE */
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
