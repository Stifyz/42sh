/*
** my_printf.h for  in /blinux_home/bazin_q/rendu/PSU_2015_my_printf/include
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 08 17:36:46 2015 Quentin Bazin
** Last update Sun Nov 29 19:23:49 2015 Quentin Bazin
*/
#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

#include <stdarg.h>
#include <stdint.h>

#define MY_FORMAT_COUNT 4

typedef struct		s_my_format
{
  char			*specifiers;
  int			(*print_func)(va_list *args, char specifier, int fd);
}			t_my_format;

typedef struct		s_my_formats
{
  int			fd;
  t_my_format		formats[MY_FORMAT_COUNT];
}			t_my_formats;

int		my_vfprintf(int fd, const char *format, va_list *args);
int		my_fprintf(int fd, const char *format, ...);
int		my_printf(const char *format, ...);

int		my_printf_print_int(va_list *args, char specifier, int fd);
int		my_printf_print_uint(va_list *args, char specifier, int fd);
int		my_printf_print_chars(va_list *args, char specifier, int fd);
int		my_printf_print_addr(va_list *args, char specifier, int fd);

int		my_printf_putchar(char c, int fd);
int		my_printf_putstr(char *str, int fd);
uint64_t	my_printf_putulnbr_base(uint64_t nb, char *base, int fd);
int64_t		my_printf_putlnbr_base(int64_t nb, char *base, int fd);
int		my_printf_showstr_oct(char *str, int fd);

#endif /* !MY_PRINTF_H_ */
