/*
** redirection.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Apr 02 13:50:51 2016 Quentin Bazin
** Last update Sat Apr 02 13:50:51 2016 Quentin Bazin
*/

#include <my.h>
#include <fcntl.h>
#include <stdlib.h>
#include "command.h"

t_redirection	*redirection_new(char *filepath, t_io_mode mode)
{
  t_redirection	*redirection;

  if (!(redirection = malloc(sizeof(t_redirection))))
    return (NULL);
  redirection->filepath = my_strdup(filepath);
  redirection->data = NULL;
  redirection->mode = mode;
  redirection->open_flags = (mode & IO_MODE_OUTPUT) ? O_WRONLY | O_CREAT : 0;
  redirection->open_flags |= (mode & IO_MODE_INPUT) ? O_RDONLY : 0;
  if (mode & IO_MODE_OUTPUT)
    redirection->open_flags |= (mode & IO_MODE_SIMPLE) ? O_TRUNC : O_APPEND;
  return (redirection);
}

t_err	redirection_check(t_redirection *redirection)
{
  char	*end_str;
  char	*line;

  if (redirection && redirection->mode == (IO_MODE_INPUT | IO_MODE_DOUBLE))
    {
      end_str = redirection->filepath;
      my_putstr("? ");
      while ((line = my_getline(0)))
	{
	  if (my_strcmp(line, end_str) == 0)
	    break;
	  redirection->data = my_strcatm(redirection->data, line);
	  redirection->data = my_strcatm(redirection->data, "\n");
	  free(line);
	  my_putstr("? ");
	}
      free(end_str);
    }
  return (0);
}

void	redirection_free(t_redirection *redirection)
{
  if (redirection)
    {
      free(redirection->filepath);
      free(redirection->data);
    }
  free(redirection);
}
