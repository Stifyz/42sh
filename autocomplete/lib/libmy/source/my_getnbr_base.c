/*
** my_getnbr_base.c for Piscine_C_J06 in /home/bazin_q/rendu/Piscine_C_J06
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Mon Oct  5 21:56:09 2015 Quentin Bazin
** Last update Fri Oct  9 14:40:12 2015 Quentin Bazin
*/

int	my_strlen(char *str);

int	my_char_pos_in_str(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (-1);
}

int		my_atoi_base(char *str, int num[2], int sign, char *base)
{
  int		i;
  int		n;
  unsigned int	tmp;
  int		base_n;

  n = 0;
  i = num[0];
  base_n = my_strlen(base);
  while (i < num[0] + num[1])
    {
      tmp = n * base_n + my_char_pos_in_str(base, str[i]);
      if (tmp <= 2147483648 && sign == -1)
	n = tmp;
      else if (tmp <= 2147483647 && sign == 1)
	n = tmp;
      else
	return (0);
      i = i + 1;
    }
  return (sign * n);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	num[2];
  int	sign;

  sign = 1;
  i = 0;
  if (!str || !base || !my_strlen(str) || !my_strlen(base))
    return (0);
  while (my_char_pos_in_str(base, str[i]) < 0)
    {
      if (str[i] != '+' && str[i] != '-')
	return (0);
      i = i + 1;
    }
  num[0] = i;
  if (i > 0 && str[i - 1] == '-')
    sign = -1;
  while (my_char_pos_in_str(base, str[i]) >= 0)
    i = i + 1;
  num[1] = i - num[0];
  return (my_atoi_base(str, num, sign, base));
}
