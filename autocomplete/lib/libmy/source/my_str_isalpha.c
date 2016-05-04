/*
** my_str_isalpha.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 18:01:10 2015 Quentin Bazin
** Last update Mon Oct  5 18:32:15 2015 Quentin Bazin
*/

int	my_str_isalpha(char *str)
{
  if (!str)
    {
      return (0);
    }
  while (*str != '\0')
    {
      if (!(*str >= 'a' && *str <= 'z') && !(*str >= 'A' && *str <= 'Z'))
	{
	  return (0);
	}
      str = str + 1;
    }
  return (1);
}
