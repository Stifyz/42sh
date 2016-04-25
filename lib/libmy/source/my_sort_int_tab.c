/*
** my_sort_int_tab.c for Piscine_C_J07 in /home/bazin_q/rendu/Piscine_C_J07/
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Tue Oct  6 11:00:48 2015 Quentin Bazin
** Last update Tue Oct  6 15:59:57 2015 Quentin Bazin
*/

int	my_swap(int *a, int *b);

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	moves;

  moves = 1;
  while (moves > 0 && tab && size > 0)
    {
      i = 0;
      moves = 0;
      while (i < size)
	{
	  if (i < size - 1 && tab[i + 1] < tab[i])
	    {
	      my_swap(&tab[i], &tab[i + 1]);
	      moves = moves + 1;
	    }
	  i = i + 1;
	}
    }
}
