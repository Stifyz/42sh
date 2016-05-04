/*
** my_str_isprintable.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 18:01:10 2015 Quentin Bazin
** Last update Sun Oct 18 13:05:05 2015 Quentin Bazin
*/

int	my_is_printable(char c)
{
  return (c > 31 && c != 127);
}

int	my_str_isprintable(char *str)
{
  if (!str)
    {
      return (0);
    }
  while (*str != '\0')
    {
      if (!my_is_printable(*str))
	{
	  return (0);
	}
      str = str + 1;
    }
  return (1);
}
