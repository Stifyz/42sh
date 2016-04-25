/*
** my_strupcase.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 17:07:51 2015 Quentin Bazin
** Last update Fri Oct 16 21:33:49 2015 Quentin Bazin
*/

char	*my_strupcase(char *str)
{
  char	*tmp;

  tmp = str;
  if (!tmp)
    {
      return (0);
    }
  while (*tmp != '\0')
    {
      if (*tmp >= 'a' && *tmp <= 'z')
	{
	  *tmp = *tmp - ('a' - 'A');
	}
      tmp = tmp + 1;
    }
  return (str);
}
