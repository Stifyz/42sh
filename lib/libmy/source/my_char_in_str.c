/*
** my_char_in_str.c for  in /blinux_home/bazin_q/rendu/PSU_2015_my_printf/lib
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sun Nov 08 17:52:23 2015 Quentin Bazin
** Last update Sun Nov 29 19:31:53 2015 Quentin Bazin
*/

int	my_char_in_str(char *str, char c)
{
  if (!str)
    return (0);
  while (*str != '\0')
    {
      if (*str == c)
	return (1);
      ++str;
    }
  return (0);
}
