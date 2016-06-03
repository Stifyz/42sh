/*
** command.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Mar 30 17:56:47 2016 Quentin Bazin
** Last update Wed Mar 30 17:56:47 2016 Quentin Bazin
*/

#include <fcntl.h>
#include <my.h>
#include <stdlib.h>
#include <unistd.h>
#include "command.h"
#include "utils.h"

t_command	*command_new(char *str)
{
  t_command	*command;

  if (!str || !(command = malloc(sizeof(t_command))))
    return (NULL);
  my_memset(command, 0, sizeof(t_command));
  /* if (!(command->argv = my_str_to_array(str, " "))) */
  /*   return (NULL); */
  command->output_fd = 1;
  return (command);
}

t_err		command_add_argument(t_command *command, char *str)
{
  t_argument	*argument;

  if (!(argument = malloc(sizeof(t_argument))))
    return (print_error(ERROR_MALLOC_FAILED));
  argument->str = str;
  argument->next = NULL;
  if (command->last_arg)
    command->last_arg->next = argument;
  command->last_arg = argument;
  if (!command->args)
    command->args = argument;
  ++command->argc;
  return (0);
}

t_err		command_create_argv(t_command *command)
{
  t_argument	*tmp;
  t_argument	*next;
  int		i;

  i = 0;
  if (!(command->argv = malloc(sizeof(char *) * (command->argc + 1))))
    return (print_error(ERROR_MALLOC_FAILED));
  my_memset(command->argv, 0, sizeof(char *) * (command->argc + 1));
  tmp = command->args;
  while (tmp)
    {
      if (!(command->argv[i] = my_strdup(tmp->str)))
	return (print_error(ERROR_MALLOC_FAILED));
      next = tmp->next;
      free(tmp);
      tmp = next;
      ++i;
    }
  return (0);
}

t_err	command_open_redirections(t_command *command)
{
  if (command->input && (command->input->mode & IO_MODE_SIMPLE))
    {
      command->input_fd = open(command->input->filepath,
			       command->input->open_flags);
      if (command->input_fd == -1)
	return (print_error(ERROR_OPEN_FAILED, command->input->filepath));
    }
  if (command->output)
    {
      command->output_fd = open(command->output->filepath,
				command->output->open_flags, 0644);
      if (command->output_fd == -1)
	return (print_error(ERROR_OPEN_FAILED, command->output->filepath));
    }
  return (0);
}

/* t_err		command_parse_redirections(t_command *command) */
/* { */
/*   t_io_mode	mode; */
/*   char		**argv; */
/*   int		i; */
/*  */
/*   i = -1; */
/*   argv = command->argv; */
/*   while (argv[++i]) */
/*     if ((mode = GET_IO_MODE(argv[i])) && IS_IRED(argv[i])) */
/*       { */
/* 	if (command->input || command->input_fd != 0) */
/* 	  return (print_error(ERROR_AMBIGUOUS_INPUT_REDIRECT)); */
/* 	if (!(command->input = redirection_new(argv[i + 1], mode))) */
/* 	  return (print_error(ERROR_MALLOC_FAILED)); */
/* 	argv[i][0] = argv[i + 1][0] = '\0'; */
/*       } */
/*     else if (mode && IS_ORED(argv[i])) */
/*       { */
/* 	if (command->output || command->output_fd != 1) */
/* 	  return (print_error(ERROR_AMBIGUOUS_OUTPUT_REDIRECT)); */
/* 	if (!(command->output = redirection_new(argv[i + 1], mode))) */
/* 	  return (print_error(ERROR_MALLOC_FAILED)); */
/* 	argv[i][0] = argv[i + 1][0] = '\0'; */
/*       } */
/*   my_epur_array(command->argv); */
/*   return (0); */
/* } */

void		command_free(t_command *command)
{
  t_command	*next;

  while (command != NULL)
    {
      my_free_str_array(command->argv);
      free(command->path);
      if (command->piped_command)
	command_free(command->piped_command);
      next = command->next;
      free(command);
      command = next;
    }
}
