/*
** my_strcapitalize.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 17:32:32 2015 Quentin Bazin
** Last update Tue Oct  6 22:51:17 2015 Quentin Bazin
*/

char	*my_strlowcase(char *str);

int	my_is_lower(char c)
{
  if (c >= 'a' && c <= 'z')
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

int	my_is_alphanum(char c)
{
  if (my_is_lower(c) || (c >= 'A' && c <= 'Z'))
    {
      return (1);
    }
  else if (c >= '0' && c <= '9')
    {
      return (1);
    }
  else
    {
      return (0);
    }
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (!str)
    {
      return (0);
    }
  my_strlowcase(str);
  while (str[i] != '\0')
    {
      if (i > 0)
	{
	  if (!my_is_alphanum(str[i - 1]) && my_is_lower(str[i]))
	    {
	      str[i] = str[i] - ('a' - 'A');
	    }
	}
      else if (my_is_lower(str[i]))
	{
	  str[i] = str[i] - ('a' - 'A');
	}
      i = i + 1;
    }
  return (str);
}
