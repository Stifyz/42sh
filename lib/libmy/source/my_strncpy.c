/*
** my_strncpy.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 10:34:22 2015 Quentin Bazin
** Last update Tue Oct  6 10:56:34 2015 Quentin Bazin
*/

int	my_strlen(char *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (!dest || !src)
    {
      return (0);
    }
  if (n < 1)
    {
      return (dest);
    }
  while (i < n && i < my_strlen(src))
    {
      dest[i] = src[i % my_strlen(src)];
      i = i + 1;
    }
  if (n > my_strlen(src))
    {
      dest[i] = '\0';
    }
  return (dest);
}
