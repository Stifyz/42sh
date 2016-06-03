/*
** test.h for test in /home/bouamar/rendu/test
**
** Made by Bouama_r
** Login   <bouamar@epitech.net>
**
** Started on  Thu Jun  2 23:20:35 2016 Bouama_r
** Last update Fri Jun  3 22:13:40 2016 Bouama_r
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

#endif
