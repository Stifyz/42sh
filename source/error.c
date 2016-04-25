/*
** error.c for  in /home/bazin_q/rendu/PSU/PSU_2015_42sh/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Apr 25 16:09:02 2016 Quentin Bazin
** Last update Mon Apr 25 16:09:02 2016 Quentin Bazin
*/

#include <my.h>
#include <my_printf.h>
#include <stdarg.h>
#include "error.h"

void	fill_error_messages(char *messages[ERROR_COUNT])
{
  messages[0] = "Unable to allocate memory";
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
  my_puterr("Error: ");
  va_start(args, error);
  my_vfprintf(2, errors[error - 1], &args);
  va_end(args);
  my_puterr("\n");
  return (error);
}
