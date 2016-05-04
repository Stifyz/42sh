/*
** my_isneg.c for Piscine_C_J03 in /home/bazin_q/rendu/Piscine_C_J03
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Sep 30 11:00:05 2015 Quentin Bazin
** Last update Tue Oct  6 10:45:58 2015 Quentin Bazin
*/

void	my_putchar(char c);

int	my_isneg(int n)
{
  if (n >= 0)
    {
      my_putchar('P');
    }
  else
    {
      my_putchar('N');
    }
  return (0);
}
