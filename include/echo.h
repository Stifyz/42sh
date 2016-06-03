/*
** test.h for test in /home/bouamar/rendu/test
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 23:20:35 2016 Bouama_r
** Last update Fri Jun  3 00:19:33 2016 Bouama_r
*/

#ifndef ECHO
#define ECHO

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>


void    my_echo(int ac, char **av);
void    disp_normal(int ac, char **av);
char    get_escaped_char(char *str, int pos);
void    flag_e(int ac, char **av);
void    my_flag_echo(int ac, char **av);
bool	my_is_octal(char c);
int     check_space(char *str);
int     main(int ac, char **av);


int	my_strlen(char *str);
int	my_char_pos_in_str(char *str, char c);
int	my_atoi_base(char *str, int num[], int sign, char *base);
int	my_getnbr_base(char *str, char *base);
void	my_putstr(char *str);
void	my_putchar(char c);

#endif
