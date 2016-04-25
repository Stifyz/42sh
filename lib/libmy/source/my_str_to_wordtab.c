/*
** my_str_to_wordtab.c for Piscine_C_J08 in /home/bazin_q/rendu/Piscine_C_J08
** 
** Made by Quentin Bazin
** Login   <bazin_q@epitech.net>
** 
** Started on  Wed Oct  7 12:23:36 2015 Quentin Bazin
** Last update Fri Dec 11 08:53:37 2015 Quentin Bazin
*/

#include <stdlib.h>
#include "my.h"

int	my_count_words(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (my_is_alphanum(str[i]))
	{
	  if ((i > 0 && !my_is_alphanum(str[i - 1])) || i == 0)
	    {
	      count = count + 1;
	    }
	}
      i = i + 1;
    }
  return (count);
}

int	my_split_words(char *str, char **array)
{
  int	i;
  int	w_pos;
  int	w_id;

  i = 0;
  w_pos = -1;
  w_id = 0;
  while (i <= my_strlen(str))
    {
      if (w_pos == -1 && i < my_strlen(str) && my_is_alphanum(str[i])
	  && ((i > 0 && !my_is_alphanum(str[i - 1])) || i == 0))
	w_pos = i;
      else if ((w_pos != -1 && i < my_strlen(str) && !my_is_alphanum(str[i]))
	       || (i == my_strlen(str) && my_is_alphanum(str[i - 1])))
	{
	  array[w_id] = my_strndup(&str[w_pos], i - w_pos);
	  if (array[w_id] == NULL)
	    return (1);
	  w_pos = -1;
	  w_id = w_id + 1;
	}
      i = i + 1;
    }
  return (0);
}

char	**my_str_to_wordtab(char *str)
{
  char	**array;
  int	words_count;

  if (str == NULL)
    {
      return (NULL);
    }
  words_count = my_count_words(str);
  if ((array = malloc((words_count + 1) * sizeof(char *))) == NULL)
    {
      return (NULL);
    }
  if (my_split_words(str, array) != 0)
    {
      free(array);
      return (NULL);
    }
  array[words_count + 1] = 0;
  return (array);
}

char	**my_str_to_array(char *str, const char *delim)
{
  char	**array;
  char	*tmp;
  int	splits;
  int	i;

  splits = 1;
  tmp = str;
  if (str == NULL)
    return (NULL);
  while ((tmp = my_strstr(tmp, delim)) != NULL && ++splits)
    tmp += my_strlen(delim);
  if ((array = malloc((splits + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = 0;
  while (i < splits && (array[i] = my_strsplit(str, delim, i)) != NULL)
    ++i;
  array[i] = NULL;
  return (array);
}

void	my_free_str_array(char **array)
{
  char	**tmp;

  tmp = array;
  while (tmp != NULL && *tmp != NULL)
    {
      free(*tmp);
      ++tmp;
    }
  free(array);
}
