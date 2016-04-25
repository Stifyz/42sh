/*
** my_strlowcase.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 17:29:30 2015 Quentin Bazin
** Last update Mon Oct  5 17:30:00 2015 Quentin Bazin
*/

char	*my_strlowcase(char *str)
{
  char	*tmp;

  tmp = str;
  if (!tmp)
    {
      return (0);
    }
  while (*tmp != '\0')
    {
      if (*tmp >= 'A' && *tmp <= 'Z')
	{
	  *tmp = *tmp + ('a' - 'A');
	}
      tmp = tmp + 1;
    }
  return (str);
}
