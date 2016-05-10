/*
** list_manipulation.c for list_manipulation in /home/audet_b/Projets/PSU_2015_minishell2/src/list/
**
** Made by Benjamin Audet
** Login   <audet_b@epitech.eu>
**
** Started on  Tue Apr  5 16:24:30 2016 Benjamin Audet
** Last update Mon May  9 15:52:17 2016 Benjamin Audet
*/

#include <sys/types.h>
#include <dirent.h>
#include <limits.h>
#include <stdlib.h>
#include "list.h"

void		replace_element(t_list *list, char *var, char *content)
{
  char		*var_new;
  t_element	*tmp;

  var_new = my_strcat(var, "=");
  tmp = list->first;
  while (tmp != NULL)
    {
      if ((my_strcmp(tmp->file_name, var)) == 0)
	tmp->file_name = my_strcat(var_new, content);
      tmp = tmp->next;
    }
}

char		*get_element(t_list *list, char *var)
{
  int		len_var;
  char		*copy_var;
  int		len;
  t_element	*tmp;

  len = my_strlen(var);
  tmp = list->first;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->file_name, var) == 0)
	{
	  len_var = my_strlen(tmp->file_name);
          copy_var = malloc(sizeof(char) * len_var + 1);
	  my_strcpy(copy_var, tmp->file_name);
	  copy_var += len;
	  return (my_strdup(copy_var));
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void		new_element(t_list *list, char *var)
{
  t_element	*new;

  new = malloc(sizeof(t_element));
  new->file_name = var;
  new->next = list->first;
  list->first = new;
}

int		my_strlen_list(t_list *list)
{
  int		i;
  t_element	*tmp;

  i = 0;
  tmp = list->first;
  while (tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return (i);
}
