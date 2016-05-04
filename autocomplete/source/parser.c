/*
** parser.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 18:05:35 2016 Quentin Bazin
** Last update Wed Mar 30 18:05:35 2016 Quentin Bazin
*/

#include <my.h>
#include <stdlib.h>
#include <unistd.h>
#include "application.h"
#include "parser.h"

t_err		parser_parse_str(t_parser	*parser,
				 t_application	*app,
				 char		*str)
{
  char		**commands;
  int		error;
  int		i;

  i = 0;
  error = 0;
  commands = my_str_to_array(str, ";");
  while (!error && commands[i])
    {
      error = parser_add_command(parser, app, commands[i]);
      ++i;
    }
  my_free_str_array(commands);
  return (error);
}

t_err		parser_add_pipe(t_parser	*parser,
				t_application	*app,
				char		*cmd)
{
  t_command	*current;
  t_err		error;
  char		**array;
  int		i;

  if (!(array = my_strspl(cmd, '|')))
    return (print_error(ERROR_MALLOC_FAILED));
  if ((error = parser_add_command(parser, app, array[0])))
    return (error);
  current = parser->last;
  i = 0;
  while (array[++i])
    {
      if (current->output)
	return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT));
      if (!(current->piped_command = parser_new_command(array[i])))
	return (print_error(ERROR_MALLOC_FAILED));
      if ((error = command_setup_pipe(current)) ||
	  (error = command_parse_redirections(current->piped_command)))
	return (error);
      current = current->piped_command;
    }
  my_free_str_array(array);
  return (0);
}

t_err		parser_add_command(t_parser		*parser,
				   t_application	*app,
				   char			*cmd)
{
  t_command	*command;
  t_err		error;

  if (my_strchr(cmd, '|'))
    return (parser_add_pipe(parser, app, cmd));
  if (!(command = parser_new_command(cmd)))
    return (print_error(ERROR_MALLOC_FAILED));
  if ((error = command_parse_redirections(command)))
    {
      command_free(command);
      return (error);
    }
  if (!parser->last && !parser->commands)
    parser->last = parser->commands = command;
  else
    {
      parser->last->next = command;
      parser->last = command;
    }
  return (0);
}

char	*parser_edit_command_str(char *cmd)
{
  char	*new;
  int	new_length;
  int	i;
  int	j;

  new_length = my_strlen(cmd) + 1;
  new_length += my_strcnt(cmd, '>') * 2 + my_strcnt(cmd, '<') * 2;
  if (!(new = malloc(new_length)))
    return (NULL);
  i = 0;
  j = 0;
  while (cmd[i])
    {
      if (i > 0 && (cmd[i - 1] == '>' || cmd[i - 1] == '<')
	  && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<')
	new[j++] = ' ';
      new[j] = cmd[i];
      if ((cmd[i + 1] == '>' || cmd[i + 1] == '<')
	  && cmd[i] != ' ' && cmd[i] != '>' && cmd[i] != '<')
	new[++j] = ' ';
      ++i;
      ++j;
    }
  new[j] = '\0';
  return (new);
}

inline t_command	*parser_new_command(char *cmd)
{
  return (command_new(parser_edit_command_str(cmd)));
}
