/*
** my_is_num.c for  in /home/bazin_q/rendu/Piscine_C_bistromathique/lib/my
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Sat Oct 31 17:38:46 2015 Quentin Bazin
** Last update Sat Oct 31 17:39:31 2015 Quentin Bazin
*/

int	my_is_num(char c)
{
  if (c >= '0' && c <= '9')
    {
      return (1);
    }
  else
    {
      return (0);
    }
}
