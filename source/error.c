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
  messages[1] = "Error: Pipe failed";
  messages[2] = "Syntax error at position %d";
  messages[3] = "%s: Too few arguments";
  messages[4] = "%s: Too many arguments";
  messages[5] = "%s: Argument must be a positive integer";
  messages[6] = "%s: %e.";
  messages[7] = "%s: End of history";
  messages[8] = "%s: Variable name must contain alphanumeric characters only";
  messages[9] = "Error: Fork failed";
  messages[10] = "Unable to open file: %s";
  messages[11] = "Ambiguous output redirect";
  messages[12] = "Ambiguous input redirect";
  messages[13] = "Invalid null command";
  messages[14] = "Can't add token to list";
  messages[15] = "Empty string";
  messages[16] = "Unexpected char at position %d";
  messages[17] = "Unexpected end of string";
  messages[18] = "Expected char '%c' at position %d";
  messages[19] = "Curses init failed";
  messages[20] = "setterm failed";
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
