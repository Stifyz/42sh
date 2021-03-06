/*
** error.c for  in /home/bazin_q/rendu/PSU/PSU_2015_minishell2/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Fri Mar 25 16:59:04 2016 Quentin Bazin
** Last update Fri Mar 25 16:59:04 2016 Quentin Bazin
*/

#include <my.h>
#include <my_printf.h>
#include <stdarg.h>
#include "error.h"

void	fill_error_messages(char *messages[ERROR_COUNT])
{
  my_memset(messages, 0, sizeof(char *) * ERROR_COUNT);
  messages[0] = "Error: Unable to allocate memory";
  messages[1] = "pipe: %e.";
  messages[2] = "Syntax error at position %d";
  messages[3] = "%s: Too few arguments.";
  messages[4] = "%s: Too many arguments.";
  messages[5] = "%s: Expression Syntax.";
  messages[6] = "%s: %e.";
  messages[7] = "%s: End of history.";
  messages[8] = "%s: Variable name must contain alphanumeric characters.";
  messages[9] = "fork: %e.";
  messages[10] = "%s: %e.";
  messages[11] = "Ambiguous output redirect.";
  messages[12] = "Ambiguous input redirect.";
  messages[13] = "Invalid null command.";
  messages[14] = "Can't add token to list";
  messages[15] = "Unexpected char at position %d";
  messages[16] = "Unexpected end of string";
  messages[17] = "Expected operator with id %d at position %d";
  messages[18] = "Curses init failed";
  messages[19] = "setterm failed";
  messages[20] = "Missing name for redirect.";
  messages[21] = "%s: %e.%s";
  messages[22] = "Alias loop.";
  messages[126] = "%s: Command not found.";
}

void	print_usage(char *program_name)
{
  my_printf("Usage: %s\n", program_name);
}

t_err		print_error(t_err error, ...)
{
  char		*errors[ERROR_COUNT];
  va_list	args;

  if (error < 0)
    return (error);
  fill_error_messages(errors);
  va_start(args, error);
  my_vfprintf(2, errors[error - 1], &args);
  va_end(args);
  my_puterr("\n");
  return (error);
}
