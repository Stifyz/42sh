/*
** my_printf.c for  in /blinux_home/bazin_q/rendu/PSU_2015_my_printf/source
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 08 17:26:28 2015 Quentin Bazin
** Last update Sun Nov 29 19:22:38 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

int		my_printf_print_format(const char	*format,
				       int		i,
				       va_list		*args,
				       t_my_formats	*formats)
{
  int		j;

  j = 0;
  if (!my_char_in_str("dibuoxXcsSp", format[i]))
    {
      my_putchar('%');
      my_putchar(format[i]);
      return (2);
    }
  while (j < MY_FORMAT_COUNT)
    {
      if (my_char_in_str(formats->formats[j].specifiers, format[i]))
	return (formats->formats[j].print_func(args, format[i], formats->fd));
      ++j;
    }
  return (-1);
}

void	my_printf_fill_formats(t_my_formats *formats)
{
  formats->formats[0].specifiers = "di";
  formats->formats[0].print_func = &my_printf_print_int;
  formats->formats[1].specifiers = "buoxX";
  formats->formats[1].print_func = &my_printf_print_uint;
  formats->formats[2].specifiers = "csS";
  formats->formats[2].print_func = &my_printf_print_chars;
  formats->formats[3].specifiers = "p";
  formats->formats[3].print_func = &my_printf_print_addr;
}

int		my_vfprintf(int fd, const char *format, va_list *args)
{
  int		i;
  int		sum;
  int		tmp;
  t_my_formats	formats;

  i = -1;
  sum = 0;
  formats.fd = fd;
  if (format == NULL)
    return (my_printf_putstr("(null)", fd));
  my_printf_fill_formats(&formats);
  while (++i < my_strlen(format))
    {
      if (format[i] == '%' && format[++i] != '%')
	if ((tmp = my_printf_print_format(format, i, args, &formats)) < 0)
	  return (tmp);
	else
	  sum += tmp;
      else
	sum += my_printf_putchar(format[i], fd);
    }
  return (sum);
}

int		my_fprintf(int fd, const char *format, ...)
{
  va_list	args;
  int		length;

  va_start(args, format);
  length = my_vfprintf(fd, format, &args);
  va_end(args);
  return (length);
}

int		my_printf(const char *format, ...)
{
  va_list	args;
  int		length;

  va_start(args, format);
  length = my_vfprintf(1, format, &args);
  va_end(args);
  return (length);
}
